#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define R_E  6372795
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

int main(void)
{
    double lat1deg = 48.935097;
    double lng1deg = 40.370483;
    double lat2deg = 20.033243;
    double lng2deg = -72.863961;

    double lat1rad = lat1deg * RAD;
    double lng1rad = lng1deg * RAD;
    double lat2rad = lat2deg * RAD;
    double lng2rad = lng2deg * RAD;

    double cl1 = cos(lat1rad);
    double cl2 = cos(lat2rad);
    double sl1 = sin(lat1rad);
    double sl2 = sin(lat2rad);

    double delta_lng = lng2rad - lng1rad;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);

    double y = sdelta_lng * cl2;
    double x = cl1 * sl2 - sl1 * cl2 * cdelta_lng;
    double angledeg = atan2(y, x) * DEG;
    double initial_bearing = (int)(angledeg + 360) % 360;

    y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad = atan2(y, x);
    double dist = anglerad * R_E;



    printf("y = %f\n", y);
    printf("x = %f\n", x);
    printf("anglerad = %f\n", anglerad);

    printf("dist = %.1f м\n", dist);
    printf("initial_bearing = %.f°\n", initial_bearing);

    return 0;
}
