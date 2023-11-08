#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct geo_nlat {
    unsigned nlat;
    unsigned sec;
    unsigned msec;
    unsigned grad;
    unsigned min;
} nlat;

struct geo_elon {
    unsigned elon;
    unsigned sec;
    unsigned msec;
    unsigned grad;
    unsigned min;
} elon;

int main(void)
{
    printf("Input coordinats of northern latitude in format gg.mm.ss,ms: ");
    while(scanf("%d %d %d.%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) < 3 && scanf("%d.%d.%d,%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input coordinats of eastern longitude in format gg.mm.ss,ms: ");
    while(scanf("%d %d %d.%d", &elon.grad, &elon.min, &elon.sec, &elon.msec) < 3 && scanf("%d.%d.%d,%d", &elon.grad, &elon.min, &elon.sec, &elon.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }
    printf("N: %03d %02d %02d.%02d\n", nlat.grad, nlat.min, nlat.sec, nlat.msec);
    printf("E: %03d %02d %02d.%02d\n", elon.grad, elon.min, elon.sec, elon.msec);

    return 0;
}

