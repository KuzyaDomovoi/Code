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
    double lat_1 = 45 + 01 / 60.0 + 00 / 3600.0 + 00 / 3600.0 / 60.0;
    double lng_1 = 45 + 00 / 60.0 + 00 / 3600.0 + 00 / 3600.0 / 60.0;
    double lat_2 = 45 + 00 / 60.0 + 00 / 3600.0 + 00 / 3600.0 / 60.0;
    double lng_2 = 45 + 00 / 60.0 + 00 / 3600.0 + 00 / 3600.0 / 60.0;

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
    int z = atan(-y / x) * 180.0 / M_PI;
    if(x < 0) {
        z = z + 180;
    }
    int z2 = (z + 180) % 360 - 180;
    z2 = -z2 * M_PI / 180.0;
    double anglerad = z2 - (2 * M_PI * floor(z2 / 2 * M_PI));
    double bearing = anglerad * 180.0 / M_PI;

    printf("\nbearing = %.f°\n", bearing);

    return 0;
} 
