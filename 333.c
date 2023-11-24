#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846
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

void calcpoint_coord(float lat1, float lng1, float bearing, float dist, double result_cl2sl2[2]) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;

    double cl1 = cos(lat_1.lat);
    double sl1 = sin(lat_1.lat);

    double cdelta_lat = dist * cos(bearing * RAD) / 111134.861111;
    double sdelta_lng = dist * sin(bearing * RAD) / 111321.377778;

    double cl2 = cl1 + cdelta_lat;
    double sl2 = sl1 + sdelta_lng;

    result_cl2sl2[0] = cl2 * DEG;
    result_cl2sl2[1] = sl2 * DEG;
}

int main(void)
{
            int res = 0;
            double result_cl2sl2[2];   

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
            printf("\nПервая точка:   lat   %.6f°\n                lng   %.6f°\n", lat_1.lat, lng_1.lng);
            calcpoint_coord(lat_1.lat, lng_1.lng, lat_1.initial_bearing, lat_1.fldist, result_cl2sl2);
            printf("Вторая точка:   lat   %.6f°\n                lng   %.6f°\n", result_cl2sl2[0], result_cl2sl2[1]);

    return 0;
}