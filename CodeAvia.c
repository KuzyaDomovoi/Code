#include <stdio.h>

int main(void)
{
    int item;
    double max_TOweigth, max_fuelreserve, cruisspeed, flrange_maxfuload, 
           flduration_maxfuload, flduration, req_engthrustcruise, engthrust_val,
           average_climspeed, climtime, airbornspeed, flrang_clim,
           fucost_clim, fucost_desc, full_fusupp, midaverage_climspeed,
           fucons_preTO, fucons_TO, fucons_clim, fusons_desc,
           fucons_final_Land_taxi, guarfusupp_unusfures, rangcruise, 
           timecruise, fucons_cruise, flrange, descspeed, desctime;

    double nM = 0.84, cya = 0.47, cxa = 0.029, k = 15.79, engthrottdegree = 0.836,
           spec_fuconscruise = 0.091, m, q, spec_fuconsclim = 0.103;
           
    printf("\n1. Расчет дальности и продолжительности\n"
                "полета на заданной скорости и высоте\n"
             "2. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
        }
    switch(item) {
    case 1:
        printf("\n  Величина тяги для ТРДД при номинал ррд в наборе на средн выс, H: ");
        while(scanf("%lf", &engthrust_val) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  Средн скор при наборе выс, км/ч: ");
        while(scanf("%lf", &average_climspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  Крейс скорость, км/ч: ");
        while(scanf("%lf", &cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  Скорость отрыва, км/ч: ");
        while(scanf("%lf", &airbornspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  Скорость на снижении, км/ч: ");
        while(scanf("%lf", &descspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("\n  макс заправка топ, кг: ");
        while(scanf("%lf", &full_fusupp) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  прогрев опроб двиг рул, кг: ");
        while(scanf("%lf", &fucons_preTO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  на взлете, кг: ");
        while(scanf("%lf", &fucons_TO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  на снижении, кг: ");
        while(scanf("%lf", &fusons_desc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  на кругу посадке заруливании, кг: ");
        while(scanf("%lf", &fucons_final_Land_taxi) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  гарант запас невыраб остаток, кг: ");
        while(scanf("%lf", &guarfusupp_unusfures) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  масса снаряж самолета, кг: ");
        while(scanf("%lf", &m) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("\n\n  время набора выс, мин: ");
        while(scanf("%lf", &climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время снижения, мин: ");
        while(scanf("%lf", &desctime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        midaverage_climspeed = 0.5 * ((airbornspeed / 3.6) + (average_climspeed / 3.6));
        flrang_clim = (average_climspeed * 3.6) * ((60 * climtime) / 1000);
        fucost_clim = (spec_fuconsclim * engthrust_val) * (climtime / 60); 
        fucons_TO = spec_fuconsclim * engthrust_val * (climtime / 60);
        fucons_cruise = full_fusupp - fucons_preTO - fucons_TO - fucons_clim - fusons_desc - fucons_final_Land_taxi - guarfusupp_unusfures;
        //k = cya / cxa;
        req_engthrustcruise = (m * 9.8) / k;
        q = (spec_fuconscruise * req_engthrustcruise) / cruisspeed;
        rangcruise = fucons_cruise / q;
        timecruise = rangcruise / cruisspeed;
        flrange = (midaverage_climspeed * climtime) + ((cruisspeed / 3.6) * timecruise / 3.6) + (descspeed * desctime);
        flduration = (climtime / 60) + timecruise + (desctime / 60);
        
        printf("q = %.2f\n", q);
        printf("\nРасполагаемый запас топлива = %.2f\n", fucons_cruise);
        printf("Дальность полета, км = %.2f\nПродолжительность полета, ч = %.2f\n", flrange, flduration);
        //printf("Дальн пол с макс заправкой топл, км = %f\n", flrange_maxfuload, flduration_maxfuload);
    case 2:
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
