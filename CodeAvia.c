#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846

bool range(int x, int a, int y)
{
    if(a >= x && a <= y)
        return true;
    return false;
}

int main(void)
{
    int item;

    double full_fusupp, engthrust_val, guarfusupp_unusfures, airbornspeed, max_TOweigth,
           fucons_preTO, fucons_TO, spec_fuconsclim = 0.091, spec_fuconscruise = 0.077,
           fucons_clim, average_climspeed, midaverage_climspeed, flrang_clim, climtime, 
           fucons_cruise, req_engthrustcruise, cruisspeed, timecruise, rangcruise,
           fucons_desc, descspeed, desctime, nM = 0.77, lifttodrag_ratio = 11.4, load_weight, 
           hourfucons, fucons_final_land_taxi, mindist_checkpoint, linturn_lead, t;

    int flduration_h, flduration_m, flrange, flduration, turn_time, turn_time_m, turn_time_s,
        turn_rad, turn_roll, turn_angle, max_aircr_speed, wind_angle, 
        magnetpath_angle, aircr_speed, wind_dir, graund_speed, drift_angle, wind_speed,
        speed_range, time_range;

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
        while(scanf("%lf", &engthrust_val) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость отрыва, км/ч: ");
        while(scanf("%lf", &airbornspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  средн скор набора выс, км/ч: ");
        while(scanf("%lf", &average_climspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время набора выс, мин: ");
        while(scanf("%lf", &climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  крейс скорость, км/ч: ");
        while(scanf("%lf", &cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость на снижении, км/ч: ");
        while(scanf("%lf", &descspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время снижения, мин: ");
        while(scanf("%lf", &desctime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }       
        printf("  масса снаряж самолета, кг: ");
        while(scanf("%lf", &load_weight) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  макс заправка топл, кг: ");
        while(scanf("%lf", &full_fusupp) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на прогрев, опроб двиг и руление, кг: ");
        while(scanf("%lf", &fucons_preTO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на взлете, кг: ");
        while(scanf("%lf", &fucons_TO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на снижении, кг: ");
        while(scanf("%lf", &fucons_desc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на кругу, посадке и заруливании, кг: ");
        while(scanf("%lf", &fucons_final_land_taxi) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  невырабатываемый остаток топл, кг: ");
        while(scanf("%lf", &guarfusupp_unusfures) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        midaverage_climspeed = 0.5 * ((airbornspeed / 3.6) + (average_climspeed / 3.6));
        flrang_clim = (average_climspeed * 3.6) * ((60 * climtime) / 1000);
        fucons_clim = (spec_fuconsclim * engthrust_val) * (climtime / 60); 
        fucons_cruise = full_fusupp - fucons_preTO - fucons_TO - fucons_clim - fucons_desc - fucons_final_land_taxi - guarfusupp_unusfures;
        req_engthrustcruise = (load_weight * 9.81) / lifttodrag_ratio;
        hourfucons = (spec_fuconscruise * req_engthrustcruise) / cruisspeed;
        rangcruise = fucons_cruise / hourfucons;
        timecruise = rangcruise / cruisspeed;
        flrange = (midaverage_climspeed * climtime) + ((cruisspeed / 3.6) * timecruise / 3.6) + (descspeed * desctime);
        flduration = (climtime * 60) + (timecruise * 3600) + (desctime * 60);
        flduration_h = (int)flduration / 3600;
        flduration_m = (int)flduration % 3600 / 60;
        printf("\nРасполагаемый запас топлива = %.f кг\n", fucons_cruise);
        printf("Дальность полета = %d км\nПродолжительность полета = %d ч %02d мин\n", flrange, flduration_h, flduration_m);
        return 0;
    case 2:
        printf("\n   1. Определение радиуса разворота по углу крена и скорости разворота\n"
                 "   2. Определение времени разворота самолета с заданным креном и скоростью разворота\n"
                 "   3. Расчет угла сноса и путевой скорости по известному вектору ветра\n"
                 "   4. Определение линейного упреждения разворота\n"
                 "   5. Расчет минимального расстояния для возможного погашения опоздания или избытка времени\n"
                 "   6. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nОпределение радиуса разворота по углу крена и скорости разворота\n");
            printf("\n   Введи через пробел значение скорости в км/ч и крена° на развороте: ");
            while(scanf("%d %d", &aircr_speed, &turn_roll) != 2) {
                printf("\nError_input!\n");
                return 0;
            }
            printf("\n   радиус разворота cо скоростью %d км/ч и креном %d° = %.f м\n", aircr_speed, turn_roll, 
                    pow(aircr_speed / 3.6, 2) / (9.81 * tan(turn_roll * M_PI / 180)));
            return 0;
        case 2:
            printf("\nОпределение времени разворота самолета с заданной скоростью, креном и углом разворота\n");
            printf("\n   Введи через пробел значение скорости в км/ч, крена° и угла° разворота: ");
            while(scanf("%d %d %d", &aircr_speed, &turn_roll, &turn_angle) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(turn_roll >= 84) {
                printf("\nError! The turn_roll can't be more than 83°!\n");
                return 0;
            }
            turn_time = (2 * M_PI * aircr_speed / 3.6) / (9.81 * tan(turn_roll * M_PI / 180)) * turn_angle / 360;
            turn_time_m = (turn_time / 60) % 60;
            turn_time_s = turn_time % 60;
            printf("\n   время разворота со скоростью %d км/ч креном %d° на угол %d° = %d мин %02d сек\n",aircr_speed, turn_roll, turn_angle, 
                     turn_time_m, turn_time_s);
            return 0;
        case 3:
            printf("\nРасчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи через пробел значение V полета с-та в км/ч, U ветра в км/ч, НВ° и курс с-та°: ");
            while(scanf("%d %d %d %d", &aircr_speed, &wind_speed, &wind_dir, &magnetpath_angle) != 4) {
                printf("\nError_input!\n");
                return 0;
            }
            if(wind_dir == magnetpath_angle) {
                drift_angle = 0;
                graund_speed = aircr_speed + wind_speed;
                printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении нав ветра %d° и курсе самолета %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                        aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
                return 0;
            }
            if(wind_dir < magnetpath_angle) {
                wind_angle = 360 + wind_dir - magnetpath_angle;
            } else
                wind_angle = wind_dir - magnetpath_angle;
            if(wind_angle == 180 || wind_angle == 0 || wind_angle == 360) {
                drift_angle = 0;
                graund_speed = aircr_speed - wind_speed;
                printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении внав етра %d° и курсе самолета %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                        aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
                return 0;
            }
            
            if(range(1, wind_angle, 179)) {
                if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                    t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * M_PI / 180.0);
                if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                    t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * M_PI / 180.0);
                if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                    t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * M_PI / 180.0);
                if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                    t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * M_PI / 180.0);
            }
            if(range(181, wind_angle, 359)) {     
                if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                    t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * M_PI / 180.0);
                if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                    t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * M_PI / 180.0);
                if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                    t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * M_PI / 180.0);
                if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                    t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * M_PI / 180.0);
            }
            
            drift_angle = rint(asin(t) * 180.0 / M_PI);
            graund_speed = aircr_speed * cos(drift_angle * M_PI / 180.0) + wind_speed * cos(wind_angle * M_PI / 180.0);
            printf("\n   wind_angel = %d\n", wind_angle);
            printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении ветра %d° и курсе самолета %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                    aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
            return 0;
        case 4:
            printf("\nОпределение линейного упреждения разворота\n");
            printf("\n   Введи через пробел угол° и радиус разворота в км: ");
            while(scanf("%d %d", &turn_angle, &turn_rad) != 2) {
                printf("\nError_input!\n");
                return 0;
            }
            linturn_lead = turn_rad * (tan((turn_angle / 2) * M_PI / 180.0));
            printf("\n   ЛУР = %.1f км\n", linturn_lead);
            return 0;
        case 5:
            printf("\nРасчет минимального расстояния для возможного погашения опоздания или избытка времени\n");
            printf("\n   Введи через пробел приб скорость полета в км/ч,  макс приб скорость в км/, " 
                   "макс возможный избыток или недостаток времени в сек: ");
            while(scanf("%d %d %d", &aircr_speed, &max_aircr_speed, &time_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(max_aircr_speed < aircr_speed) {
                printf("\nError_input! The max_aircr_speed can't be less than aircr_speed!\n");
                return 0; 
            }   
            speed_range = max_aircr_speed - aircr_speed;
            mindist_checkpoint = ((double)aircr_speed * max_aircr_speed / speed_range * time_range / 3600);
            printf("\n   при избытке скорости = %d км/ч\n", speed_range);
            printf("   минимальное расстояние до РТ = %.1f км\n", mindist_checkpoint);
            return 0;
        case 6:
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
