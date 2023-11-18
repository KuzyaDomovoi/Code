#include <stdio.h>
#include <stdlib.h>

#define TIME_ADD(A, B) ((A) + (B));
#define TIME_SUB(A, B) ((A) - (B));

int main(void)
{
    int calc_mode;
    int time_1, time_2;

    int hour_1 = time_1 / 3600;
    int min_1 = (time_1 / 60) % 60;
    int sec_1 = time_1 % 60;
    
    int hour_2 = time_2 / 3600;
    int min_2 = (time_2 / 60) % 60;
    int sec_2 = time_2 % 60;
    
    printf("Input time_1 in format: 'hour.min.sec': ");
    while(scanf("%d.%d.%d", &hour_1, &min_1, &sec_1) != 3) {
        printf("\nError input!\n");
        return 0;
    }
    printf("Input time_2 in format: 'hour.min.sec': ");
    while(scanf("%d.%d.%d", &hour_2, &min_2, &sec_2) != 3) {
        printf("\nError input!\n");
        return 0; 
    }

    time_1 = hour_1 * 3600 + min_1 * 60 + sec_1;
    time_2 = hour_2 * 3600 + min_2 * 60 + sec_2;

    printf("\n1. addition\n"
             "2. substraction\n");
    printf("Select the mode of time calculation: ");

    if(scanf("%d", &calc_mode) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(calc_mode) {
    case 1:
        printf("\nAddition:\n");
        int time_res_add = TIME_ADD(time_1, time_2);
        int hour_res_add = time_res_add / 3600;
        int min_res_add = (time_res_add / 60) % 60;
        int sec_res_add = time_res_add % 60;
        printf("%d:%02d:%02d + %d:%02d:%02d = %d:%02d:%02d\n", 
                hour_1, min_1, sec_1, hour_2, min_2, sec_2, hour_res_add, min_res_add, sec_res_add);
        return 0;
    case 2:
        printf("\nSubstraction:\n");
        int time_res_sub = TIME_SUB(time_1, time_2);
        int hour_res_sub = time_res_sub / 3600;
        int min_res_sub = abs((time_res_sub / 60) % 60);
        int sec_res_sub = abs(time_res_sub % 60);
        printf("%d:%02d:%02d - %d:%02d:%02d = %d:%02d:%02d\n", 
                hour_1, min_1, sec_1, hour_2, min_2, sec_2, hour_res_sub, min_res_sub, sec_res_sub);
        return 0;
    case 3:
        printf("\nExit.\n");
        return 0;
    default:
        printf("\nIncorrect symbol!\n");
        return 0;
    }
    return 0;
}