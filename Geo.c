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

struct geo_elng {
    unsigned elng;
    unsigned sec;
    unsigned msec;
    unsigned grad;
    unsigned min;
} elng;

int main(void)
{
    printf("Input coordinats of northern latitude in format gg mm ss.ms: ");
    while(scanf(" %d %d %d.%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) < 3 && scanf("%d.%d.%d,%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input coordinats of eastern longitude in format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng.grad, &elng.min, &elng.sec, &elng.msec) < 3 && scanf("%d.%d.%d,%d", &elng.grad, &elng.min, &elng.sec, &elng.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }
    printf("N: %02d %02d %02d.%02d\n", nlat.grad, nlat.min, nlat.sec, nlat.msec);
    printf("E: %03d %02d %02d.%02d\n", elng.grad, elng.min, elng.sec, elng.msec);

    return 0;
}

