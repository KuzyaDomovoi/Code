#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct geo_lat {
    double lat;
    unsigned sec; unsigned msec;
    unsigned deg; unsigned min;
} lat_1;

struct geo_lng {
    double lng;
    unsigned sec; unsigned msec;
    unsigned deg; unsigned min;
} lng_1;

bool range2(int x, int a, int y) {
    if(a < x || a > y)
        return true;
    return false;
}

bool input_verif_lat(int a, int b, int c, int d, int res) {
    if(range2(3, res, 4)) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-90, a, 90)) {
        printf("\nIncorrect input! Range of latitude is -90...90\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59)) {
        printf("\nIncorrect input! Range of min and sec is 0...59\n");
        return true;
    }
    if(range2(0, d, 99)) {
        printf("\nIncorrect input! Range of msec is 0...99\n");
        return true;
    }
    if(range2(-89, a, 89) && (b > 0 || c > 0 || d > 0)) {
        printf("\nIncorrect input! If the latitude has value -90 or 90, the values of min, sec and msec should be 00 only\n");
        return true;
    } else return false;
}

bool input_verif_lng(int a, int b, int c, int d, int res) {
    if(range2(3, res, 4)) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-180, a, 180)) {
        printf("\nIncorrect input! Range of latitude is -180...180\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59)) {
        printf("\nIncorrect input! Range of min and sec is 0...59\n");
        return true;
    }
    if(range2(0, d, 99)) {
        printf("\nIncorrect input! Range of msec is 0...99\n");
        return true;
    }
    if(range2(-179, a, 179) && (b > 0 || c > 0 || d > 0)) {
        printf("\nIncorrect input! If the longitude has value -180 or 180, the values of min, sec and msec should be 00 only\n");
        return true;
    } else return false;
}

void coord_transfer_deg(double deg, int res[2], float res2[1]) {
    int dd = trunc(deg);
    int mm = trunc((deg - dd) * 60);
    float ss = ((deg - dd) * 60 - mm) * 60;

    res[0] = dd;
    res[1] = mm;
    res2[0] = ss;
}

void coord_transfer_wgs84(int deg, int min, int sec, int msec, float res[2]) {
    double lat = lat_1.deg + lat_1.min / 60.0 + lat_1.sec / 3600.0 + lat_1.msec / 3600.0 / 60.0;
    double lng = lng_1.deg + lng_1.min / 60.0 + lng_1.sec / 3600.0 + lng_1.msec / 3600.0 / 60.0;

    res[0] = lat;
    res[1] = lng;
}
int main(void)
{
    int item;
    double lat_deg;
    double lng_deg;
    int res = 0;

    printf("\n1. Преобразование координат из гг мм сс мс в градусы\n"
             "2. Преобразование координат из градусов в гг мм сс.мс\n"
             "3. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(item) {
    case 1:
        printf("\nПреобразование координат из гг мм сс мс в градусы\n");
        printf("\n   Введи через пробел координаты WGS-84 широты: ");
        res = scanf("%d %d %d %d", &lat_1.deg, &lat_1.min, &lat_1.sec, &lat_1.msec);
        if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, res) != 0)
            return 0;
        printf("   Введи через пробел координаты WGS-84 долготы: ");
        res = scanf("%d %d %d %d", &lng_1.deg, &lng_1.min, &lng_1.sec, &lng_1.msec);
        if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, lng_1.msec, res) !=0)
            return 0;
        float res[2];
        coord_transfer_wgs84(lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, res);
        printf("\n   lat  %02d° %02d' %02d.%02d''\n   lng %03d° %02d' %02d.%02d''\n",
                lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, lng_1.deg, lng_1.min, lng_1.sec, lng_1.msec);
        printf("\n   lat  %.6f°\n   lng %03.6f°\n", res[0], res[1]);
        return 0;
    case 2:
        printf("\nПреобразование координат из градусов в гг мм сс.мс\n");
        printf("\n   Введи координаты широты: ");
        if(scanf("%lf", &lat_deg) != 1) {
            printf("incorrect input!\n");
            return 0;
        }    
        printf("   Введи координаты долготы: ");
        if(scanf("%lf", &lng_deg) != 1) {
                printf("incorrect input!\n");
                return 0;
        } 
        int lat_res[2];
        float lat_res2[1];
        int lng_res[2];
        float lng_res2[1];
        coord_transfer_deg(lat_deg, lat_res, lat_res2);
        coord_transfer_deg(lng_deg, lng_res, lng_res2);
        printf("\n   lat  %02d° %02d' %.2f''\n   lng %03d° %02d' %.2f''\n", 
                lat_res[0], lat_res[1], lat_res2[0], lng_res[0], lng_res[1], lng_res2[0]);
    case 3:
        printf("\nEnd of program\n");
        return 0;
    default:
        printf("\nIncorrect input!\n");
        return 0;
    }

    return 0;
}
