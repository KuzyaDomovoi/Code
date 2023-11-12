#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct geo_nlat {
    double lat;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} lat;

bool range2(int x, int a, int y) {
    if(a < x || a > y)
        return true;
    return false;
}

bool input_verif(int a, int b, int c, int d, int result) {
    if(range2(3, result, 4)) {
        printf("Incorrect input! should be entered 3...4 value!\n");
        return 0;
    
    if(range2(-90, a, 90)) 
        printf("Incorrect input! Range of lat is -90...90\n");
        return 0;
    
    if(range2(0, b, 59) || range2(0, c, 59) || range2(0, d, 59)) 
        printf("Incorrect input! Range of min, sec and msec is 0...59\n");
        return 0;
    } else 
        return false;
}

 int main(void)
{
    printf("\n   Введи через пробел координаты WGS-84 для широты первой точки: ");

    /*if(scanf("%d %d %d %d", &lat.grad, &lat.min, &lat.sec, &lat.msec) != 4) {
        printf("Incorrect input! It should be entered 4 value!\n");
        return 0;
    }
    if(range2(-90, lat.grad, 90)) {
        printf("Incorrect input! Range of lat is -90...90\n");
        return 0;
    }
    if(range2(0, lat.min, 59) || range2(0, lat.sec, 59) || range2(0, lat.msec, 59)) {
        printf("Incorrect input! Range of min, sec and msec is 0...59\n");
        return 0;   
    }*/
    do {
        int result = scanf("%d %d %d.%d", &lat.grad, &lat.min, &lat.sec, &lat.msec);
        input_verif(lat.grad, lat.min, lat.sec, lat.msec, result);
    } while(false);

    printf("\nГеоточка: lat %02d° %02d' %02d.%02d''\n", lat.grad, lat.min, lat.sec, lat.msec);

    return 0;
}
