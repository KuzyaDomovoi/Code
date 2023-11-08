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
    while(scanf("%d.%d.%d,%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    } 
    
    printf("Input coordinats of eastern longitude in format gg.mm.ss,ms: ");
    while(scanf("%d.%d.%d,%d", &elon.grad, &elon.min, &elon.sec, &elon.msec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    }
    //nlat.nlat = nlat.grad * 3600 + nlat.min * 60 + nlat.sec;

    //elon.elon = elon.grad * 3600 + elon.min * 60 * elon.sec;


    printf("N: %03d:%02d:%02d,%02d\n", nlat.grad, nlat.min, nlat.sec, nlat.msec);
    printf("E: %03d:%02d:%02d,%02d\n", elon.grad, elon.min, elon.sec, elon.msec);

    return 0;
}
    /*
    nlat.sec = nlat % 60;
    nlat.min = (nlat / 60) % 60;
    nlat.grad = nlat / 3600;*/

    /* 
    elon.sec = elon % 60; 
    elon.min = (elon / 60) % 60;
    elon.grad = elon / 3600;*/
