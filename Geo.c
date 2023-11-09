#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E 6378.1
#define R_P 6357.8
#define S_E 40075.017
#define S_M 40007.863

struct geo_nlat {
    unsigned nlat;
    unsigned sec;
    unsigned msec;
    unsigned grad;
    unsigned min;
} nlat_1;

struct geo_elng {
    unsigned elng;
    unsigned sec;
    unsigned msec;
    unsigned grad;
    unsigned min;
} elng_1;

struct geo_nlat nlat_2;
struct geo_elng elng_2;

int main(void)
{
    printf("Input the northern latitude coordinates of the first point in the format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &nlat_1.grad, &lat_1.min, &lat_1.sec, &lat_1.msec) < 3 && scanf("%d.%d.%d,%d", &lat_1.grad, &lat_1.min, &lat_1.sec, &lat_1.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input eastern longitude coordinates of the first point in the format ggg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng_1.grad, &elng_1.min, &elng_1.sec, &elng_1.msec) < 3 && scanf("%d.%d.%d,%d", &elng_1.grad, &elng_1.min, &elng_1.sec, &elng_1.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }

     printf("Input the northern latitude coordinates of the first point in the format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &nlat_2.grad, &nlat_2.min, &nlat_2.sec, &nlat_2.msec) < 3 && scanf("%d.%d.%d,%d", &nlat_2.grad, &nlat_2.min, &nlat_2.sec, &nlat_2.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input eastern longitude coordinates of the first point in the format ggg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng_2.grad, &elng_2.min, &elng_2.sec, &elng_2.msec) < 3 && scanf("%d.%d.%d,%d", &elng_2.grad, &elng_2.min, &elng_2.sec, &elng_2.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }

    double lat_1 = nlat_1.grad * 3600 + nlat_1.min * 60 + nlat_1.sec * 60 + nlat_1.msec * 0.60;
    double lng_1 = elng_1.grad * 3600 + elng_1.min * 60 + elng_1.sec * 60 + elng_1.msec * 0.60;
    
    double lat_2 = nlat_2.grad * 3600 + nlat_2.min * 60 + nlat_2.sec * 60 + nlat_2.msec * 0.60;
    double lng_2 = elng_2.grad * 3600 + elng_2.min * 60 + elng_2.sec * 60 + elng_2.msec * 0.60;

    //double angle = acos(sin(lng_1) * sin(lng_2) * cos(lat_1 - lat_2) + cos(lng_1) * cos(lng_2)); // calc...
    //double flight_range_2 = ((M_PI * ((R_P + R_E) / 2) * angle) / 180.0) * 1000;

    double flight_range = (R_P + R_E) / 2 * acos(sin(lng_1 * M_PI / 180.0) * sin(lng_2 * M_PI / 180.0) * cos((lat_1 - lat_2) * M_PI / 180.0) + cos(lng_1 * M_PI / 180.0) * cos(lng_2 * M_PI / 180.0)) * 180 / M_PI * 1000;

    printf("N:  %02d %02d %02d.%02d\n", nlat.grad, nlat.min, nlat.sec, nlat.msec);
    printf("E: %03d %02d %02d.%02d\n", elng.grad, elng.min, elng.sec, elng.msec);
    printf("flight_range = %.2f\n", flight_range);

    return 0;
}

