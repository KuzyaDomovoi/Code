#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct geo_nlat {
    unsigned nlat;
    unsigned sec;
    unsigned grad;
    unsigned min;
} nlat;

struct geo_elon {
    unsigned elon;
    unsigned sec;
    unsigned grad;
    unsigned min;
} elon;

int main(void)
{
    printf("Input coordinats of northern latitude in format gg.mm.ss: ");
    while(scanf("%d.%d.%d", &nlat.grad, &nlat.min, &nlat.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    } 
    
    printf("Input coordinats of eastern longitude in format gg.mm.ss: ");
    while(scanf("%d.%d.%d", &elon.grad, &elon.min, &elon.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    }
    //geo_nlat.nlat = geo_nlat.grad * 3600 + geo_nlat.min * 60 + geo_nlat.sec;

    //geo_elon.elon = geo_elon.grad * 3600 + geo_elon.min * 60 * geo_elon.sec;


    printf("nlat: %03d:%02d:%02d\n", nlat.grad, nlat.min, nlat.sec);
    printf("elon: %03d:%02d:%02d\n", elon.grad, elon.min, elon.sec);

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
