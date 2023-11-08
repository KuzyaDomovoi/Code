#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct geo_nlat {
    unsigned nlat;
    unsigned sec;
    unsigned grad;
    unsigned min;
} geo_nlat;

struct geo_elon {
    unsigned elon;
    unsigned sec;
    unsigned grad;
    unsigned min;
} geo_elon;

int main(void)
{
    printf("Input coordinats of nlat in format gg.mm.ss: ");
    while(scanf("%d.%d.%d", &geo_nlat.grad, &geo_nlat.min, &geo_nlat.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    } 
    
    printf("Input coordinats of elon in format gg.mm.ss: ");
    while(scanf("%d.%d.%d", &geo_elon.grad, &geo_elon.min, &geo_elon.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    }
    //geo_nlat.nlat = geo_nlat.grad * 3600 + geo_nlat.min * 60 + geo_nlat.sec;

    //geo_elon.elon = geo_elon.grad * 3600 + geo_elon.min * 60 * geo_elon.sec;


    printf("nlat: %03d:%02d:%02d\n", geo_nlat.grad, geo_nlat.min, geo_nlat.sec);
    printf("elon: %03d:%02d:%02d\n", geo_elon.grad, geo_elon.min, geo_elon.sec);

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
