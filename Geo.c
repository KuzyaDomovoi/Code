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
    float angle = 1.0; // calc...
/*
    printf("Input coordinats of northern latitude in format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) < 3 && scanf("%d.%d.%d,%d", &nlat.grad, &nlat.min, &nlat.sec, &nlat.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input coordinats of eastern longitude in format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng.grad, &elng.min, &elng.sec, &elng.msec) < 3 && scanf("%d.%d.%d,%d", &elng.grad, &elng.min, &elng.sec, &elng.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }
    printf("N:  %02d %02d %02d.%02d\n", nlat.grad, nlat.min, nlat.sec, nlat.msec);
    printf("E: %03d %02d %02d.%02d\n", elng.grad, elng.min, elng.sec, elng.msec);
*/

    double flight_range_E = (M_PI * R_E * angle) / 180.0;
    double flight_range_P = (M_PI * R_P * angle) / 180.0;
    double flight_range = (M_PI * ((R_P + R_E) / 2) * angle) / 180.0;

    printf ("\nAngle = %.1f°:\n   flight range E = %.2f км\n   flight range P = %.2f км\n   flight range m = %.2f км\n", angle, flight_range_E, flight_range_P, flight_range);

    return 0;
}

