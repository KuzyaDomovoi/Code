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
    printf("Input coordinats of nlat in format gg.mm.ss: ");
    while(scanf("%d.%d.%d\n", &nlat.grad, &nlat.min, &nlat.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    }    
    
    printf("Input coordinats of elon in format gg.mm.ss: ");
    while(scanf("%d.%d.%d\n", &elon.grad, &elon.min, &elon.sec) != 3) {
        printf("Incorrect input!\n");
        return 0;
    }

    printf("nlat: %03d:%02d:%02d\n", nlat.grad, nlat.min, nlat.sec);
    printf("elon: %03d:%02d:%02d\n", elon.grad, elon.min, elon.sec);

    return 0;
}
    /*nlat = nlat.grad * 3600 + nlat.min * 60 + nlat.sec;
    nlat.sec = nlat % 60;
    nlat.min = (nlat / 60) % 60;
    nlat.grad = nlat / 3600;*/

    /*elon = elon.grad * 3600 + elon.min * 60 * elon.sec; 
    elon.sec = elon % 60; 
    elon.min = (elon / 60) % 60;
    elon.grad = elon / 3600;*/
