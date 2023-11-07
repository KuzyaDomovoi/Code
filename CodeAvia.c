#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct flrange_flduration {
    double engthrust_val;
    int airbornspeed; int average_climspeed; int climtime; int cruisspeed;
    int descspeed; int desctime; int load_weight; int full_fusupp; int fucons_preTO; int fucons_TO; 
    int fucons_desc; int fucons_final_land_taxi; int guarfusupp_unusfures;

    double midaverage_climspeed; double flrang_clim; double fucons_clim; double fucons_cruise;
    double req_engthrustcruise; double lifttodrag_ratio; double hourfucons;
    double spec_fuconsclim; double spec_fuconscruise; double rangcruise;
    double timecruise; 
    int flrange; int flduration; int flduration_h; int flduration_m; 
    } flight;

struct fltime_flangle_flspeed {
    int turn_time; int turn_time_m; int turn_time_s; int turn_rad; int turn_roll; int turn_angle;
    int max_aircr_speed; int wind_angle; int magnetpath_angle; int aircr_speed; int wind_dir;
    int graund_speed; int drift_angle; int wind_speed; int speed_range; int time_range; int lateral_line;
    int flcurr_range; int flrem_range; int course_correction; int track_range; int course_correction_curr;
    int course_correction_rem;
    double linturn_lead; double t; double mindist_checkpoint; double range_turnlead; 
} maneuver;

#define M_PI 3.14159265358979323846
#define G 9.81
#define K 0.0175

bool range(int x, int a, int y) {
    if(a >= x && a <= y)
        return true;
    return false;
}

int main(void)
{
    int item;

    printf("\n1. Расчет дальности и продолжительности полета на заданной скорости и высоте\n"
             "2. Расчеты на маневрирование\n"
             "3. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(item) {
    case 1:
        printf("\n  величина тяги для ТРДД при номинал ррд в наборе на средн выс, H: ");
        while(scanf("%lf", &flight.engthrust_val) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  аэродинамическое качество с-та: ");
        while(scanf("%lf", &flight.lifttodrag_ratio) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость отрыва, км/ч: ");
        while(scanf("%d", &flight.airbornspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скор набора выс, км/ч: ");
        while(scanf("%d", &flight.average_climspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время набора выс, сек: ");
        while(scanf("%d", &flight.climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  крейс скорость, км/ч: ");
        while(scanf("%d", &flight.cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость на снижении, км/ч: ");
        while(scanf("%d", &flight.descspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время снижения, сек: ");
        while(scanf("%d", &flight.desctime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }       
        printf("  масса снаряж самолета, кг: ");
        while(scanf("%d", &flight.load_weight) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  макс заправка топл, кг: ");
        while(scanf("%d", &flight.full_fusupp) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  удельный расход топл в наборе, кг: ");
        while(scanf("%lf", &flight.spec_fuconsclim) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  удельный расход топл по мрш в гп, кг: ");
        while(scanf("%lf", &flight.spec_fuconscruise) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на прогрев, опроб двиг и руление, кг: ");
        while(scanf("%d", &flight.fucons_preTO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на взлете, кг: ");
        while(scanf("%d", &flight.fucons_TO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на снижении, кг: ");
        while(scanf("%d", &flight.fucons_desc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на кругу, посадке и заруливании, кг: ");
        while(scanf("%d", &flight.fucons_final_land_taxi) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  невырабатываемый остаток топл, кг: ");
        while(scanf("%d", &flight.guarfusupp_unusfures) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        flight.midaverage_climspeed = 0.5 * (flight.airbornspeed + flight.average_climspeed);
        flight.flrang_clim = (flight.average_climspeed * 3.6) * ((flight.climtime / 3600) / 1000);
        flight.fucons_clim = (flight.spec_fuconsclim * flight.engthrust_val) * (flight.climtime / 3600 ); 
        flight.fucons_cruise = flight.full_fusupp - flight.fucons_preTO - flight.fucons_TO - flight.fucons_clim - flight.fucons_desc - flight.fucons_final_land_taxi - flight.guarfusupp_unusfures;
        flight.req_engthrustcruise = (flight.load_weight * G) / flight.lifttodrag_ratio;
        flight.hourfucons = (flight.spec_fuconscruise * flight.req_engthrustcruise) / flight.cruisspeed;
        flight.rangcruise = flight.fucons_cruise / flight.hourfucons;
        flight.timecruise = flight.rangcruise / flight.cruisspeed;
        flight.flrange = (flight.midaverage_climspeed * flight.climtime / 3600) + (flight.cruisspeed * flight.timecruise) + (flight.descspeed * flight.desctime / 3600);
        flight.flduration = flight.climtime + (flight.timecruise * 3600) + flight.desctime;
        flight.flduration_h = (int)flight.flduration / 3600;
        flight.flduration_m = (int)flight.flduration % 3600 / 60;
        printf("\nРасполагаемый запас топлива = %.f кг\n", flight.fucons_cruise);
        printf("Дальность полета = %d км\nПродолжительность полета = %d ч %02d мин\n", flight.flrange, flight.flduration_h, flight.flduration_m);
        return 0;
    case 2:
        printf("\n   1. Определение радиуса разворота по углу крена и скорости разворота\n"
                 "   2. Определение времени разворота самолета с заданным креном и скоростью разворота\n"
                 "   3. Расчет угла сноса и путевой скорости по известному вектору ветра\n"
                 "   4. Определение линейного упреждения разворота и длины дуги угла р-та\n"
                 "   5. Расчет минимального расстояния для возможного погашения опоздания или избытка времени\n"
                 "   6. Расчет поправки в курс по расстоянию и боковому уклонению\n"
                 "   7. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! input out of range list!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nОпределение радиуса разворота по углу крена и скорости разворота\n");
            printf("\n   Введи через пробел значение скорости в км/ч и крена° на развороте: ");
            while(scanf("%d %d", &maneuver.aircr_speed, &maneuver.turn_roll) != 2) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500) {
                printf("\nError! Input the unreal speed for an aircraft or for the wind!\n");
                return 0;
            }
            if(maneuver.turn_roll > 83) {
                printf("\nError! The turn_roll can't be more than 83°!\n");
                return 0;
            }
            printf("\n   радиус разворота cо скоростью %d км/ч и креном %d° = %.f м\n", maneuver.aircr_speed, maneuver.turn_roll, 
                    pow(maneuver.aircr_speed / 3.6, 2) / (9.81 * tan(maneuver.turn_roll * M_PI / 180)));
            return 0;
        case 2:
            printf("\nОпределение времени разворота самолета с заданной скоростью, креном и углом разворота\n");
            printf("\n   Введи через пробел значение скорости в км/ч, крена° и угла° разворота: ");
            while(scanf("%d %d %d", &maneuver.aircr_speed, &maneuver.turn_roll, &maneuver.turn_angle) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500) {
                printf("\nError! Input the unreal speed for an aircraft or for the wind!\n");
                return 0;
            }
            if(maneuver.turn_roll > 83) {
                printf("\nError! The turn_roll can't be more than 83°!\n");
                return 0;
            }
            maneuver.turn_time = (2 * M_PI * maneuver.aircr_speed / 3.6) / (9.81 * tan(maneuver.turn_roll * M_PI / 180)) * maneuver.turn_angle / 360;
            maneuver.turn_time_m = (maneuver.turn_time / 60) % 60;
            maneuver.turn_time_s = maneuver.turn_time % 60;
            printf("\n   время разворота со скоростью %d км/ч креном %d° на угол %d° = %d мин %02d сек\n", 
                    maneuver.aircr_speed, maneuver.turn_roll, maneuver.turn_angle, maneuver.turn_time_m, maneuver.turn_time_s);
            return 0;
        case 3:
            printf("\nРасчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи через пробел значение скорость с-та в км/ч, скорость ветра в км/ч, курс полета с-та° и направление нав ветера°: ");
            while(scanf("%d %d %d %d", &maneuver.aircr_speed, &maneuver.wind_speed, &maneuver.magnetpath_angle, &maneuver.wind_dir) != 4) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500 || maneuver.wind_speed < 0 || maneuver.wind_speed > 300) {
                printf("\nError! Input the unreal speed for an aircraft or for the wind!\n");
                return 0;
            }
            if(maneuver.magnetpath_angle < 0 || maneuver.magnetpath_angle > 360 || maneuver.wind_dir < 0 || maneuver.wind_dir > 360) {
                printf("\nError! Angle can't be less 0° or more than 360°\n");
                return 0;
            }
            if(maneuver.wind_dir == maneuver.magnetpath_angle) {
                maneuver.drift_angle = 0;
                maneuver.graund_speed = maneuver.aircr_speed + maneuver.wind_speed;
               printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.graund_speed);
                return 0;
            }
            if(maneuver.wind_dir < maneuver.magnetpath_angle) {
                maneuver.wind_angle = 360 + maneuver.wind_dir - maneuver.magnetpath_angle;
            } else
                maneuver.wind_angle = maneuver.wind_dir - maneuver.magnetpath_angle;
            if(maneuver.wind_angle == 180 || maneuver.wind_angle == 0 || maneuver.wind_angle == 360) {
                maneuver.drift_angle = 0;
                maneuver.graund_speed = maneuver.aircr_speed - maneuver.wind_speed;
                printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.graund_speed);
                return 0;
            }
            if(range(1, maneuver.wind_angle, 179)) {
                if(range(0, maneuver.magnetpath_angle, 180) && range(0, maneuver.wind_dir, 180))
                    maneuver.t = -1 * (double)maneuver.wind_speed / maneuver.aircr_speed * sin(maneuver.wind_angle * M_PI / 180.0);
                if(range(0, maneuver.magnetpath_angle, 180) && range(181, maneuver.wind_dir, 360))
                    maneuver.t = -1 * (double)maneuver.wind_speed / maneuver.aircr_speed * sin(maneuver.wind_angle * M_PI / 180.0);
                if(range(181, maneuver.magnetpath_angle, 360) && range(0, maneuver.wind_dir, 180))
                    maneuver.t = -1 * (double)maneuver.wind_speed / maneuver.aircr_speed * sin(maneuver.wind_angle * M_PI / 180.0);
                if(range(181, maneuver.magnetpath_angle, 360) && range(181, maneuver.wind_dir, 360))
                    maneuver.t = -1 * (double)maneuver.wind_speed / maneuver.aircr_speed * sin(maneuver.wind_angle * M_PI / 180.0);
            }
            if(range(181, maneuver.wind_angle, 359)) {     
                if(range(0, maneuver.magnetpath_angle, 180) && range(0, maneuver.wind_dir, 180))
                    maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle - 180) * M_PI / 180.0);
                if(range(0, maneuver.magnetpath_angle, 180) && range(181, maneuver.wind_dir, 360))
                    maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle - 180) * M_PI / 180.0);
                if(range(181, maneuver.magnetpath_angle, 360) && range(0, maneuver.wind_dir, 180))
                    maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle - 180) * M_PI / 180.0);
                if(range(181, maneuver.magnetpath_angle, 360) && range(181, maneuver.wind_dir, 360))
                    maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle - 180) * M_PI / 180.0);
            }
            maneuver.drift_angle = rint(asin(maneuver.t) * 180.0 / M_PI);
            maneuver.graund_speed = maneuver.aircr_speed * cos(maneuver.drift_angle * M_PI / 180.0) + maneuver.wind_speed * cos(maneuver.wind_angle * M_PI / 180.0);
            printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.graund_speed);
            return 0;
        case 4:
            printf("\nОпределение линейного упреждения разворота и длины дуги угла р-та\n");
            printf("\n   Введи через пробел скорость с-та в км/ч, угол° и радиус разворота в км: ");
            while(scanf("%d %d %d", &maneuver.aircr_speed, &maneuver.turn_angle, &maneuver.turn_rad) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500) {
                printf("\nError! Input the unreal speed for an aircraft!\n");
                return 0;
            }
            maneuver.linturn_lead = maneuver.turn_rad * (tan((maneuver.turn_angle / 2) * M_PI / 180.0));
            maneuver.range_turnlead = K * maneuver.turn_rad * maneuver.turn_angle;
            printf("\n   ЛУР = %.1f км\n   Длина дуги УР = %.1f км\n", maneuver.linturn_lead, maneuver.range_turnlead);
            return 0;
        case 5:
            printf("\nРасчет минимального расстояния для возможного погашения опоздания или избытка времени\n");
            printf("\n   Введи через пробел приб скорость полета в км/ч,  макс приб скорость в км/ч, " 
                   "макс возможный избыток или недостаток времени в сек: ");
            while(scanf("%d %d %d", &maneuver.aircr_speed, &maneuver.max_aircr_speed, &maneuver.time_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.max_aircr_speed < maneuver.aircr_speed) {
                printf("\nError_input! The max_aircr_speed can't be less than aircr_speed!\n");
                return 0; 
            }   
            maneuver.speed_range = maneuver.max_aircr_speed - maneuver.aircr_speed;
            maneuver.mindist_checkpoint = ((double)maneuver.aircr_speed * maneuver.max_aircr_speed / maneuver.speed_range * maneuver.time_range / 3600);
            printf("\n   при избытке скорости = %d км/ч\n", maneuver.speed_range);
            printf("   минимальное расстояние до РТ = %.1f км\n", maneuver.mindist_checkpoint);
            return 0;
        case 6:
            printf("\nРасчет поправки в курс по расстоянию и боковому уклонению\n");
            printf("\n   Введи через пробел линейное боковое уклонение в км, общее расстояние до РТ в км, пройденное/оставшееся расстояние до РТ в км: ");
            while(scanf("%d %d %d", &maneuver.lateral_line, &maneuver.track_range, &maneuver.flcurr_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            maneuver.flrem_range = maneuver.track_range - maneuver.flcurr_range;
            maneuver.course_correction_curr = (tan((double)maneuver.lateral_line / maneuver.flcurr_range) * 180.0 / M_PI);
            maneuver.course_correction_rem = (tan((double)maneuver.lateral_line / maneuver.flrem_range) * 180.0 / M_PI);
            maneuver.course_correction = (tan((double)maneuver.lateral_line / maneuver.flcurr_range) * 180.0 / M_PI) + (tan((double)maneuver.lateral_line / maneuver.flrem_range) * 180.0 / M_PI);
            printf("   при БУ = %d° поправки в курс:\n      по пройденному расстоянию = %d°\n      по оставшемуся расстоянию = %d°\n      полная = %d°\n", maneuver.lateral_line, maneuver.course_correction_curr, maneuver.course_correction_rem, maneuver.course_correction);
            return 0;
        case 7:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 3:
        printf("\nEnd of program\n");
        return 0;
    default:
        printf("\nIncorrect input!\n");
        return 0;
    }
    return 0;
}

/*
    scanf("Потребн длина ВПП при взлете, м: ", &req_rwaylen_TO);
    scanf("Потребн длина ВПП при посадке, м: ", &req_rwaylen_land);
    scanf("Прак потолок, м: ", &prac_flceil);
*/