#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6372795
#define RAD  M_PI / 180.0

int main(void)
{
    double lat1 = 77.1539;
    double lng1 = -139.398;
    double lat2= -77.1804;
    double lng2 = -139.55;

    double cl1 = cos(lat1);
    double cl2 = cos(lat2);
    double sl1 = sin(lat1);
    double sl2 = sin(lat2);

    double delta_lng = lng2 - lng1;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);

    double y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad = atan2(y, x);
    double dist = anglerad * R_E;

    printf("\nlat_1 = %f\n", lat1);
    printf("lat_2 = %f\n", lat2);
    printf("lng_1 = %f\n", lng1);
    printf("lng_2 = %f\n", lng2);

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
