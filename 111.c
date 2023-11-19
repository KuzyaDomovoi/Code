#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6372795
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI


int main(void)
{
    double lat1 = 77.1539;
    double lat2 = -139.398;
    double lng1 = -77.1804;
    double lng2 = -139.55;

    double lat1rad = lat1 * RAD;
    double lat2rad = lat2 * RAD;
    double lng1rad = lng1 * RAD;
    double lng2rad = lng2 * RAD;

    double cl1 = cos(lat1rad);
    double cl2 = cos(lat2rad);
    double sl1 = sin(lat1rad);
    double sl2 = sin(lat2rad);

    double delta_lng = lng2rad - lng1rad;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);

    double y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad = atan2(y, x);
    double dist = anglerad * R_E;

    printf("\nlat_1rad = %f\n", lat1rad);
    printf("lat_2rad = %f\n", lat2rad);
    printf("lng_1rad = %f\n", lng1rad);
    printf("lng_2rad = %f\n", lng2rad);

    printf("\ncl1 = %f\n", cl1);
    printf("cl2 = %f\n", cl2);
    printf("sl1 = %f\n", sl1);
    printf("sl2 = %f\n", sl2);

    printf("\ndelta_lng = %f\n", delta_lng);
    printf("cdelta_lng = %f\n", cdelta_lng);
    printf("sdelta_lng = %f\n", sdelta_lng);

    printf("y = %f\n", y);
    printf("x = %f\n", x);
    printf("anglerad = %f\n", anglerad);

    printf("dist = %.1f\n", dist);

    return 0;
}
