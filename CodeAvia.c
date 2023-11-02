#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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
           fucons_desc, descspeed, desctime, nM = 0.77, k = 11.4, m, q, fucons_final_Land_taxi; 
    int flduration_h, flduration_m, flrange, flduration;

    int turn_time, turn_time_m, turn_time_s, turn_rad, turn_roll, turn_angle, wind_angle, 
        magnetpath_angle, aircr_speed, wind_dir,graund_speed, drift_angle, wind_speed;
    double t;

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
        while(scanf("%lf", &m) != 1) {
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
        while(scanf("%lf", &fucons_final_Land_taxi) != 1) {
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
        fucons_cruise = full_fusupp - fucons_preTO - fucons_TO - fucons_clim - fucons_desc - fucons_final_Land_taxi - guarfusupp_unusfures;
        req_engthrustcruise = (m * 9.81) / k;
        q = (spec_fuconscruise * req_engthrustcruise) / cruisspeed;
        rangcruise = fucons_cruise / q;
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
                 "   4. Выход\n");
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
                    pow(aircr_speed / 3.6, 2) / (9.81 * tan(turn_roll * 3.14 / 180)));
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
            turn_time = (2 * 3.14 * aircr_speed / 3.6) / (9.81 * tan(turn_roll * 3.14 / 180)) * turn_angle / 360;
            turn_time_m = (turn_time / 60) % 60;
            turn_time_s = turn_time % 60;
            printf("\n   время разворота со скоростью %d км/ч креном %d° на угол %d° = %d мин %02d сек\n",aircr_speed, turn_roll, turn_angle, 
                     turn_time_m, turn_time_s);
            return 0;
        case 3:
            printf("\n Расчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи через пробел значение V полета с-та в км/ч, U ветра в км/ч, НВ° и Курс с-та°: ");
            while(scanf("%d %d %d %d", &aircr_speed, &wind_speed, &wind_dir, &magnetpath_angle) != 4) {
                printf("\nError_input!\n");
                return 0;
            }
            if(wind_dir == magnetpath_angle) {
                drift_angle = 0;
                graund_speed = aircr_speed + wind_speed;
                printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении нав ветра %d° и курс самолета %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                        aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
                return 0;
            }
            if(wind_dir < magnetpath_angle) {
                wind_angle = 360 + wind_dir - magnetpath_angle;
                if(wind_angle == 180 || wind_angle == 0 || wind_angle == 360) {
                    drift_angle = 0;
                    graund_speed = aircr_speed - wind_speed;
                    printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении ветра %d° и МПУ %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                            aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
                return 0;
                }
                if(wind_angle >= 1 || wind_angle <= 179) {
                    if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                }
                if(wind_angle >= 181 || wind_angle <= 359) {    
                    if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                }
            }
            if(wind_dir > magnetpath_angle) {
                wind_angle = wind_dir - magnetpath_angle;
                if(wind_angle == 180 || wind_angle == 0 || wind_angle == 360) {
                    drift_angle = 0;
                    graund_speed = aircr_speed - wind_speed;
                    printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении нав ветра %d° и курс самолета %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                            aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
                    return 0;
                }
                 if(wind_angle >= 1 || wind_angle <= 179) {
                    if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                        t = -1 * (double)wind_speed / aircr_speed * sin(wind_angle * 3.14 / 180.0);
                }
                if(wind_angle >= 181 || wind_angle <= 359) {    
                    if(range(0, magnetpath_angle, 180) && range(0, wind_dir, 180))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(0, magnetpath_angle, 180) && range(181, wind_dir, 360))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(0, wind_dir, 180))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                    if(range(181, magnetpath_angle, 360) && range(181, wind_dir, 360))
                        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
                }
            }
            drift_angle = rint(asin(t) * 180.0 / 3.14);
            graund_speed = aircr_speed * cos(drift_angle * 3.14 / 180.0) + wind_speed * cos(wind_angle * 3.14 / 180.0);
            printf("\n   wind_angel = %d\n", wind_angle);
            printf("   t = %.2f\n", t);
            printf("   wind_angle + drift_angle = %d\n", wind_angle + drift_angle);
            printf("   sin(wind_angle + drift_angle) = %.2f\n", sin((wind_angle + drift_angle) *3.14 / 180.0));
            printf("   sin(wind_angle) = %.2f\n", sin(wind_angle * 3.14 / 180.0));
            printf("   sin((wind_angle + drift_angle) / sin(wind_angle) = %.2f\n", sin((wind_angle + drift_angle) * 3.14 / 180.0) / sin(wind_angle * 3.14 / 180.0));
            printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении ветра %d° и МПУ %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
                    aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
            return 0;
        case 4:
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
