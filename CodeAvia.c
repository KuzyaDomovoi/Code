#include <stdio.h>

int main(void)
{
    int item;
    double max_TOweigth, max_fuelreserve, cruisspeed, flrange_maxfuload, 
           flduration_maxfuload, flduration, req_engthrustcruise, engthrust_val,
           average_climbspeed, climtime, airbornspeed, flrang_clim,
           fucost_clim, fucost_desc, avail_fures, full_fusupp, midaverage_climbspeed,
           fucons_preTO, fucons_TO, fucons_clim, fusons_desc,
           fucons_final_Land_taxi, guarfusupp_unusfures, lcruise, 
           tcruise, mTcruise, flrange, Vdesc, tdesc, hcruise;

    double nM = 0.84, cya = 0.47, cxa = 0.029, k = 15.79, engthrottdegree = 0.836,
           spec_fuconscruise = 0.091, m, spec_fuconsclim = 0.103;
           
    printf("1. Расчет дальности и продолжительности\n"
              "полета на заданной скорости и высоте\n"
           "2. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
        }
    switch(item) {
    case 1:
        printf("Расчет затрат топлива и дальности полета\n"
              "на участкае набора высоты\n\n");
        printf("Величина тяги для ТРДД при номинал ррд в наборе на средн выс, кН: ");
        while(scanf("%lf", &engthrust_val) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Средн скор при наборе выс, км/ч: ");
        while(scanf("%lf", &average_climbspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Крейс скорость, км/ч: ");
        while(scanf("%lf", &cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Скорость отрыва, км/ч: ");
        while(scanf("%lf", &airbornspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Время набора выс пол, сек: ");
        while(scanf("%lf", &climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Расчет располагаемого запаса топлива\n\n");
        printf("макс заправка топ, кг: ");
        while(scanf("%lf", &full_fusupp) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("прогрев опроб двиг рул, кг: ");
        while(scanf("%lf", &fucons_preTO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("взлет, кг: ");
        while(scanf("%lf", &fucons_TO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("высота гориз полета, м: ");
        while(scanf("%lf", &hcruise) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("снижение, кг: ");
        while(scanf("%lf", &fusons_desc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("круг посадка заруливание: ");
        while(scanf("%lf", &fucons_final_Land_taxi) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("гарант запас невыраб остаток: ");
        while(scanf("%lf", &guarfusupp_unusfures) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Расчет дальности и продолжительности\n"
                  "полета на заданной скорости и высоте\n\n");    
        printf("Макс запас топл, кг:  ");
        while(scanf("%lf", &max_fuelreserve) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Тяга двигателя, кН: ");
        while(scanf("%lf", &engthrust) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Скорость набора выс, км/ч: ");
        while(scanf("%lf", &average_climbspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Скорость крес на выс пот, км/ч: ");
        while(scanf("%lf", &cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Скорость на снижении, км/ч: ");
        while(scanf("%lf", &Vdesc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Время набора выс, с: ");
        while(scanf("%lf", &climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Масса самолета, кг: ");
        while(scanf("%lf", &m) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("Время снижения, с: ");
        while(scanf("%lf", &tdesc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        midaverage_climbspeed = 0.5 * (airbornspeed + average_climbspeed);
        flrang_clim = average_climbspeed * ((60 * climtime) / 1000);
        fucost_clim = (spec_fuconsclim * engthrust_val) * (climtime / 60); 
        fucons_TO = spec_fuconsclim * engthrust_val * (climtime / 60);
        fucons_clim = (spec_fuconsclim * engthrust_val) * (climtime / 60);
        avail_fures = full_fusupp - fucons_preTO - fucons_TO - fucons_clim - fusons_desc - fucons_final_Land_taxi - guarfusupp_unusfures;
        //k = cya / cxa;
        req_engthrustcruise = (m * 9.8) / k;
        q = (spec_fuconscruise * req_engthrustcruise) / (3.6 * cruisspeed);
        lcruise = mTcruise / q;
        tcruise = lcruise / (3.6 * cruisspeed);
        flrange = (midaverage_climbspeed * climtime) + (cruisspeed * tcruise) + (Vdesc * tdesc);
        flduration = (climtime / 60) + tcruise + (tdesc / 60);
        //flduration_maxfuload = 
        //flrange_maxfuload = 

        printf("Располагаемый запас топлива = %f", avail_fures);
        printf("Дальность полета, км = %f\nПродолжительность полета, ч = %f\n", flrange, flduration);
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
