#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6372795

struct geo_nlat {
    double lat;
    int sec; int msec;
    int grad; int min;
} nlat_1;

struct geo_elng {
    double lng;
    int sec; int msec;
    int grad; int min;
} elng_1;

struct geo_nlat nlat_2;
struct geo_elng elng_2;

int main(void)
{
    double lat_1 = 77.1539;
    double lng_1 = 120.398;
    double lat_2 = 77.1804;
    double lng_2 = 129.55;

    nlat_1.lat = lat_1 * M_PI / 180.0;
    elng_1.lng = lng_1 * M_PI / 180.0;
    nlat_2.lat = lat_2 * M_PI / 180.0;
    elng_2.lng = lng_2 * M_PI / 180.0;

    double cl1 = cos(nlat_1.lat);
    double cl2 = cos(nlat_2.lat);
    double sl1 = sin(nlat_1.lat);
    double sl2 = sin(nlat_2.lat);
    double delta = elng_2.lng - elng_1.lng;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    double x = (cl1 * sl2) - (sl1 * cl2 * cdelta);
    double y = sdelta * cl2;
    double z;
    if(x < 0) {
        z = z + 180.0;
        z = -((z + 180.0 / 360.0) - 180.0) * M_PI / 180.0;
    } else
        z = atan(-y / x) * 180.0 / M_PI;
    double anglerad = z - (2 * M_PI * floor(z / (2 * M_PI)));
    double bearing = anglerad * 180.0 / M_PI;

    printf("cl1 = %f\n", cl1);
    printf("cl2 = %f\n", cl2);
    printf("sl1 = %f\n", sl1);
    printf("sl2 = %f\n", sl2);
    printf("delta = %f\n", delta);
    printf("cdelta = %f\n", cdelta);
    printf("sdelta = %f\n", sdelta);
    printf("\nx = %f\n", x);
    printf("y = %f\n", y);
    printf("z = %f\n", z);
    printf("anglerad = %f\n", anglerad);
    printf("\nbearing = %.f°\n", bearing);

    return 0;
} 
