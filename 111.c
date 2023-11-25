#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6371008.8
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

int main(void)
{
    double lat1deg = 48.935432;
    double lng1deg = 40.370483;
    double lat2deg = 20.033241;
    double lng2deg = -72.863960;

    double lat1rad = lat1deg * RAD;
    double lng1rad = lng1deg * RAD;
    double lat2rad = lat2deg * RAD;
    double lng2rad = lng2deg * RAD;

    double cl1 = cos(lat1rad);
    double cl2 = cos(lat2rad);
    double sl1 = sin(lat1rad);
    double sl2 = sin(lat2rad);

    double delta_lng = lng2rad - lng1rad;
    double delta_lat = lat2rad - lat1rad;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);
    double cdelta_lat = cos(delta_lat);
    double sdelta_lat = sin(delta_lat);

    double y = sdelta_lng * cl2;
    double x = cl1 * sl2 - sl1 * cl2 * cdelta_lng;
    double angledeg = atan2(y, x) * DEG;
    double initial_bearing = angledeg + 360;

    y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad = atan2(y, x);
    double dist = anglerad * R_E;

    printf("anglerad = %.2f°\n", anglerad);
    printf("anglerdeg = %.2f°\n", angledeg);
    printf("dist = %.1f м\n", dist);
    printf("initial_bearing = %.2f°\n", initial_bearing);

    return 0;
}
