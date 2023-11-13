#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846
#define G    9.8
#define K    0.0175
#define R_E  6378137
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

struct geo_nlat {
    double lat;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} lat_1;

struct geo_elng {
    double lng;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} lng_1;

struct geo_nlat lat_2;
struct geo_elng lng_2;

void calcfldist_bear(double lat1, double lng1, double lat2, double lng2, double result[2]) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);
    double delta = lng_2.lng - lng_1.lng;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    double x = (cl1 * sl2) - (sl1 * cl2 * cdelta);
    double y = sdelta * cl2;
    double z;
    if(x < 0) {
        z = -((z + 180.0 / 360.0) - 180.0) * RAD;
    } else
        z = atan(-y / x) * DEG;
    double anglerad = (z - (2 * M_PI * floor(z / (2 * M_PI))));
    double bearing = (anglerad * DEG);

    y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
    x = sl1 * sl2 + cl1 * cl2 * cdelta;
    anglerad = atan2(y, x);
    double flight_dist = anglerad * R_E;

    result[0] = flight_dist;
    result[1] = bearing;
}

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
    int flcurr_range; int flrem_range; int flight_track; 
    
    double linturn_lead; double t; double mindist_checkpoint; double range_turnlead;
    double course_correction_curr; double course_correction_rem; double course_correction;
} maneuver;

bool range(int x, int a, int y) {
    if(x >= a && a <= y)
        return true;
    return false;
}

bool range2(int x, int a, int y) {
    if(a < x || a > y)
        return true;
    return false;
}

bool input_verif(int a, int b, int c, int d, int res) {
    if(range2(3, res, 4)) {
        printf("Incorrect input! should be entered 3...4 value!\n");
        return true;
    }
    if(range2(-90, a, 90)){
        printf("Incorrect input! Range of latitude is -90...90\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59) || range2(0, d, 59)) {
        printf("Incorrect input! Range of min, sec and msec is 0...59\n");
        return true;
    } else return false;
}

int main(void)
{
    int item;
    int res = 0;

    printf("\n1. Расчет дальности и продолжительности полета на заданной скорости и высоте\n"
             "2. Расчет дальности между двумя точками заданными географическими координатами\n"
             "3. Расчеты на маневрирование\n"
             "4. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(item) {
    case 1:
        printf("Расчет дальности и продолжительности полета на заданной скорости и высоте\n");
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
        printf("\nРасчет дальности между двумя точками заданными географическими координатами\n");
        printf("\n   Введи через пробел координаты WGS-84 для широты первой точки: ");
        res = scanf("%d %d %d %d", &lat_1.grad, &lat_1.min, &lat_1.sec, &lat_1.msec);
        if(input_verif(lat_1.grad, lat_1.min, lat_1.sec, lat_1.msec, res) != 0)
            return 0;
        printf("   Введи через пробел координаты WGS-84 для долготы первой точки: ");
        res = scanf("%d %d %d %d", &lng_1.grad, &lng_1.min, &lng_1.sec, &lng_1.msec);
        input_verif(lng_1.grad, lng_1.min, lng_1.sec, lng_1.msec, res);
        
        printf("\n   Введи через пробел координаты WGS-84 для широты второй точки: ");
        res = scanf("%d %d %d %d", &lat_2.grad, &lat_2.min, &lat_2.sec, &lat_2.msec);
        input_verif(lat_2.grad, lat_2.min, lat_2.sec, lat_2.msec, res);
        
        printf("   Введи через пробел координаты WGS-84 для долготы второй точки: ");
        res = scanf("%d %d %d %d", &lng_2.grad, &lng_2.min, &lng_2.sec, &lng_2.msec);
        input_verif(lng_2.grad, lng_2.min, lng_2.sec, lng_2.msec, res);
        
        double lat1 = lat_1.grad + lat_1.min / 60.0 + lat_1.sec / 3600.0 + lat_1.msec / 3600.0 / 60.0;
        double lng1 = lng_1.grad + lng_1.min / 60.0 + lng_1.sec / 3600.0 + lng_1.msec / 3600.0 / 60.0;
        double lat2 = lat_2.grad + lat_2.min / 60.0 + lat_2.sec / 3600.0 + lat_2.msec / 3600.0 / 60.0;
        double lng2 = lng_2.grad + lng_2.min / 60.0 + lng_2.sec / 3600.0 + lng_2.msec / 3600.0 / 60.0;

        double result[2];
        calcfldist_bear(lat1, lng1, lat2, lng2, result);

        printf("\nПервая точка: lat  %02d° %02d' %02d.%02d''\n              lng %03d° %02d' %02d.%02d''\n",
                lat_1.grad, lat_1.min, lat_1.sec, lat_1.msec, lng_1.grad, lng_1.min, lng_1.sec, lng_1.msec);
        printf("Вторая точка: lat  %02d° %02d' %02d.%02d''\n              lng %03d° %02d' %02d.%02d''\n",
                lat_2.grad, lat_2.min, lat_2.sec, lat_2.msec, lng_2.grad, lng_2.min, lng_2.sec, lng_2.msec);
        printf("\nРасстояние = %.f м\nНачальный азимут = %.f°\n", result[0], result[1]);
        return 0;
    case 3:
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
            printf("\n   Введи через пробел приб скорость полета в км/ч, макс приб скорость в км/ч, " 
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
            while(scanf("%d %d %d", &maneuver.lateral_line, &maneuver.flight_track, &maneuver.flcurr_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            maneuver.flrem_range = maneuver.flight_track - maneuver.flcurr_range;
            maneuver.course_correction_curr = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * 180.0 / M_PI);
            maneuver.course_correction_rem = (atan((double)maneuver.lateral_line / maneuver.flrem_range) * 180.0 / M_PI);
            maneuver.course_correction = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * 180.0 / M_PI) + (atan((double)maneuver.lateral_line / maneuver.flrem_range) * 180.0 / M_PI);
            printf("   при ЛБУ = %d км:\n      боковое уклонение = УС = %.f°\n      дополнительная ПК = %.f°\n      полная ПК = %.f°\n", maneuver.lateral_line, maneuver.course_correction_curr, maneuver.course_correction_rem, maneuver.course_correction);
            return 0;
        case 7:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 4:
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