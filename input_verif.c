#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct geo_nlat {
    double lat;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} lat;

bool range2(int x, int a, int y) {
    if(a < x && y > a)
        return true;
    return false;
}

bool input_verif(int grad, int min, int sec, int msec) {
    if(range2(-90, grad, 90)) {
       printf("Incorrect input!\n"); 
    }
    if(range2(0, min, 59) || range2(0, sec, 59) || range2(0, msec, 59)) {
        printf("Incorrect input! Range of min, sec and msec is 0...59\n");
    }      
}
 int main(void)
{
    printf("\n   Введи через пробел координаты WGS-84 для широты первой точки: ");
    while(scanf("%d %d %d.%d", &lat.grad, &lat.min, &lat.sec, &lat.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }

    input_verif(lat.grad, lat.min, lat.sec, lat.msec);

    printf("\nГеоточка: lat %02d° %02d' %02d.%02d''\n", lat.grad, lat.min, lat.sec, lat.msec);

    return 0;
} 
