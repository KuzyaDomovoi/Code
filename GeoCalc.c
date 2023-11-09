#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6378100
#define R_P  6357800

struct geo_nlat {
    double lat;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} nlat_1;

struct geo_elng {
    double lng;
    unsigned sec; unsigned msec;
    unsigned grad; unsigned min;
} elng_1;

struct geo_nlat nlat_2;
struct geo_elng elng_2;

double calcfldist(double lat_1, double lng_1, double lat_2, double lng_2) {
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

    double y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta;

    double ad = atan2(y, x);
    double flight_dist = ad * (R_E + R_P) / 2;
    
    double x2 = (cl1 * sl2) - (sl1 * cl2 * cdelta);
    double y2 = sdelta * cl2;
    int z = atan(-y2 / x2) * 180.0 / M_PI;
    if(x < 0) {
        z = z + 180;
    }
    int z2 = (z + 180) % 360 - 180;
    z2 = -z2 * M_PI / 180.0;
    double anglerad2 = z2 - (2 * M_PI * floor(z2 / 2 * M_PI));
    double bearing = anglerad2 * 180.0 / M_PI;
        
    return flight_dist; 
    return bearing;
}

int main(void)
{
    printf("Input the northern latitude coordinates of the first point in the format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &nlat_1.grad, &nlat_1.min, &nlat_1.sec, &nlat_1.msec) < 3 && 
          scanf("%d.%d.%d,%d", &nlat_1.grad, &nlat_1.min, &nlat_1.sec, &nlat_1.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input the eastern longitude coordinates of the first point in the format ggg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng_1.grad, &elng_1.min, &elng_1.sec, &elng_1.msec) < 3 && 
          scanf("%d.%d.%d,%d", &elng_1.grad, &elng_1.min, &elng_1.sec, &elng_1.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }
    printf("\nInput the northern latitude coordinates of the first point in the format gg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &nlat_2.grad, &nlat_2.min, &nlat_2.sec, &nlat_2.msec) < 3 && 
          scanf("%d.%d.%d,%d", &nlat_2.grad, &nlat_2.min, &nlat_2.sec, &nlat_2.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    } 
    printf("Input the eastern longitude coordinates of the first point in the format ggg mm ss.ms: ");
    while(scanf("%d %d %d.%d", &elng_2.grad, &elng_2.min, &elng_2.sec, &elng_2.msec) < 3 && 
          scanf("%d.%d.%d,%d", &elng_2.grad, &elng_2.min, &elng_2.sec, &elng_2.msec) > 4) {
        printf("Incorrect input!\n");
        return 0;
    }
    
    double lat_1 = nlat_1.grad + nlat_1.min / 60 + nlat_1.sec / 3600 + nlat_1.msec / 3600 / 60;
    double lng_1 = elng_1.grad + elng_1.min / 60 + elng_1.sec / 3600 + elng_1.msec / 3600 / 60;
    double lat_2 = nlat_2.grad + nlat_2.min / 60 + nlat_2.sec / 3600 + nlat_2.msec / 3600 / 60;
    double lng_2 = elng_2.grad + elng_2.min / 60 + elng_2.sec / 3600 + elng_2.msec / 3600 / 60;

    printf("\nFirst point:  N  %02d° %02d' %02d.%02d''   E %03d° %02d' %02d.%02d''\n",
            nlat_1.grad, nlat_1.min, nlat_1.sec, nlat_1.msec, elng_1.grad, elng_1.min, elng_1.sec, elng_1.msec);
    printf("Second point: N  %02d° %02d' %02d.%02d''   E %03d° %02d' %02d.%02d''\n",
            nlat_2.grad, nlat_2.min, nlat_2.sec, nlat_2.msec, elng_2.grad, elng_2.min, elng_2.sec, elng_2.msec);
    printf("\nFlight distance = %.f м\nInitial bearing = %.f°\n", calcfldist(lat_1 , lng_1, lat_2, lng_2));

    return 0;
}
