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
        printf("Incorrect input\n");
        return true;
    } else return false;
}

int input_transfer_time(int h, int m, int s) {
    int transfer = h * 3600 + m * 60 + s;
    return transfer;
}

int calc_time(int a, int b) {
    int add = a + b;
    return add;
}

void output_transfer_time(int t, int time[3]) {
    time[0] = t / 3600;
    time[1] = (t / 60) % 60;
    time[2] = t % 60;
}

int main(void)
{   
    int input;

    printf("\nTime-calculator\n");
    printf("\nInput time_1 in format 'hour.min.sec': ");
    input = scanf("%d.%d.%d", &time_1.hour, &time_1.min, &time_1.sec);
    if(input_time(time_1.hour, time_1.min, time_1.sec, input) != 0) {
        return 0;
    }
    printf("Input time_2 in format 'hour.min.sec': ");
    input = scanf("%d.%d.%d", &time_2.hour, &time_2.min, &time_2.sec);
    if(input_time(time_2.hour, time_2.min, time_2.sec, input) != 0) {
        return 0;
    }
    int transfer_1 = input_transfer_time(time_1.hour, time_1.min, time_1.sec);
    int transfer_2 = input_transfer_time(time_2.hour, time_2.min, time_2.sec);

    int add = calc_time(transfer_1, transfer_2);
    
    int time[3];
    output_transfer_time(add, time);
    printf("\ntime = %d:%02d:%02d\n", time[0], time[1], time[2]);
    
    return 0;     
}
