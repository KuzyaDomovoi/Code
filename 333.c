#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846
#define R_E  6372795
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

struct geo_lat {
    float lat;
    float sec; int min;
    int deg; 
    float initial_bearing;
    float fldist;
} lat_1;

struct geo_lng {
    float lng;
    float sec; int min;
    int deg;
} lng_1;

struct geo_lat lat_2;
struct geo_lng lng_2;

void calcpoint_coord(float lat1, float lng1, float bearing, float dist, double result[3]) {
    double cl1 = cos(lat1 * RAD);
    double sl1 = sin(lat1 * RAD);
    double cbear = cos(bearing * RAD);
    double sbear = sin(bearing * RAD);
    double cdist = cos(dist / R_E);
    double sdist = sin(dist / R_E);

    double lat2 = asin(sl1 * cdist + cl1 * sdist * cbear) * DEG;
    double cl2 = cos(lat2 * RAD);
    double sl2 = sin(lat2 * RAD);
    double lng2 = lng1 + atan2(sbear * sdist * cl1, cdist - sl1 * sl2) * DEG;

    double delta_lng2 = lng1 * RAD - lng2 * RAD;
    double sdelta_lng2 = sin(delta_lng2);
    double cdelta_lng2 = cos(delta_lng2);

    double y = sdelta_lng2 * cl1;
    double x = cl2 * sl1 - sl2 * cl1 * cdelta_lng2;
    double angledeg = atan2(y, x) * DEG;
    double end_bearing = (int)(angledeg + 180) % 360;

    result[0] = lat2;
    result[1] = lng2;
    result[2] = end_bearing;
}

int main(void)
{
            double result[3];

            printf("\nРасчет координат второй точки по координатам WGS-84 формата гг.гггггг\n");
            printf("\n   Введи координаты гг.гггггг широты первой точки: ");
            if(scanf("%f", &lat_1.lat) != 1) {
                printf("\nIncorect Input!\n");
                return 0;
            }
            printf("   Введи координаты ггг.гггггг долготы первой точки: ");
            if(scanf("%f", &lng_1.lng) != 1) {
                printf("\nIncorect Input!\n");
                return 0;
            }
            printf("\n   Введи дальность до второй точки в м: ");
            if(scanf("%f", &lat_1.fldist) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("\n   Введи азимут на вторую точку в °: ");
            if(scanf("%f", &lat_1.initial_bearing) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            calcpoint_coord(lat_1.lat, lng_1.lng, lat_1.initial_bearing, lat_1.fldist, result);
            printf("\nВторая точка:   lat   %.6f°\n                lng   %.6f°\n   end_bear = %.1f\n", result[0], result[1], result[2]);
    
    return 0;
}