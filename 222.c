#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void coord_transfer_wgs84(float deg, float min, float sec, float msec, float result[2]) {
    float lat, lng;
    if(deg < 0) {
        lat = -1.0 * (abs(deg) + min / 60.0 + sec / 3600.0 + msec / 3600.0 / 60.0);
    } else
        lat = deg + min / 60.0 + sec / 3600.0 + msec / 3600.0 / 60.0;

    if(deg < 0) {
        lng =  -1.0 * (abs(deg) + min / 60.0 + sec / 3600.0 + msec / 3600.0 / 60.0);
    } else
    lng = deg + min / 60.0 + sec / 3600.0 + msec / 3600.0 / 60.0 ;

    result[0] = lat;
    result[1] = lng;
}

int main(void)
{
    float result1[2];
    float result2[2];
    coord_transfer_wgs84(20, 01, 59, 67, result1);
    coord_transfer_wgs84(-72, 51, 50, 26, result2);

    printf("lat = %f\n", result1[0]);
    printf("lng = %f\n", result2[1]);

    return 0;
}