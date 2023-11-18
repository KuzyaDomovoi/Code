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
    return h * 3600 + m * 60 + s;
}

int calc_time(int a, int b, int res[2]) {
    int add = a + b;
    int sub = a - b;
    res[0] = add;
    res[1] = sub;
}

void output_transfer_time(int t, int time[3]) {
    time[0] = t / 3600;
    time[1] = abs((t / 60) % 60);
    time[2] = abs(t % 60);
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
    int transf_1 = input_transfer_time(time_1.hour, time_1.min, time_1.sec);
    int transf_2 = input_transfer_time(time_2.hour, time_2.min, time_2.sec);

    int res[2];
    calc_time(transf_1, transf_2, res);
    int add = res[0];
    int sub = res[1];

    int time[3];
    output_transfer_time(add, time);
    printf("\nAdd_time = %d:%02d:%02d\n", time[0], time[1], time[2]);
    
    output_transfer_time(sub, time);
    printf("Sub_time = %d:%02d:%02d\n", time[0], time[1], time[2]);
    
    return 0;     
}
