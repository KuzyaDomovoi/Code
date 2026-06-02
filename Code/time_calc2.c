#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct time_calc {
    int time;
    int hour;
    int min;
    int sec;
} time_1;

struct time_calc time_2;

bool input_time(int h, int m, int s, int input) {
    if(input != 3) {
        printf("\nIt should be entered hh.mm.ss\n");
        return true;
    } else return false;
}

int input_transfer_time(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void calc_time(int a, int b, int res[2]) {
    res[0] = a + b;
    res[1] = a - b;
}

void output_transfer_time(int t, int time[3]) {
    time[0] = t / 3600;
    time[1] = abs((t / 60) % 60);
    time[2] = abs(t % 60);
}

int main(void)
{   
    int input, calc_mode;
    int res1[2]; int res2[2];
    int time1[3]; int time2[3];

    printf("\nTime-calculator\n");
    printf("\nEnter time_1 in format hh.mm.ss: ");
    input = scanf("%d.%d.%d", &time_1.hour, &time_1.min, &time_1.sec);
    if(input_time(time_1.hour, time_1.min, time_1.sec, input) != false) {
        return 0;
    }
    int transf_1 = input_transfer_time(time_1.hour, time_1.min, time_1.sec);
    
    printf("Enter time_2 in format hh.mm.ss: ");
    input = scanf("%d.%d.%d", &time_2.hour, &time_2.min, &time_2.sec);
    if(input_time(time_2.hour, time_2.min, time_2.sec, input) != false) {
        return 0;
    }
    int transf_2 = input_transfer_time(time_2.hour, time_2.min, time_2.sec);

    printf("\n1. addition\n"
             "2. substraction\n");
    printf("Select the calc mode: ");

    if(scanf("%d", &calc_mode) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(calc_mode) {
    case 1:
        calc_time(transf_1, transf_2, res1);
        output_transfer_time(res1[0], time1);
        printf("\n%d:%02d:%02d + %d:%02d:%02d = %d:%02d:%02d\n", 
                time_1.hour, time_1.min, time_1.sec, time_2.hour, 
                time_2.min, time_2.sec, time1[0], time1[1], time1[2]);
        return 0;
    case 2:
        calc_time(transf_1, transf_2, res2);
        output_transfer_time(res2[1], time2);
        printf("\n%d:%02d:%02d - %d:%02d:%02d = %d:%02d:%02d\n", 
                time_1.hour, time_1.min, time_1.sec, time_2.hour, 
                time_2.min, time_2.sec, time2[0], time2[1], time2[2]);
        return 0;
    case 3:
        printf("\nExit\n");
        return 0;
    default:
        printf("\nIncorrect symbol!\n");
        return 0;
    }
    return 0;     
}
