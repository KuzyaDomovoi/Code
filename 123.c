#include <stdio.h>
#include <math.h>

#define G    9.80665
#define M    29
#define R    8.31447
#define T0   273.16 // °C;
#define P0   101.325 // 760 мм рт ст;
#define p0   1.225
#define dV   -1

int main(void)
{

    double airtemp_h = -17.5;
    double aircr_alt = 5;
    double airspeed_kmh = 220;
    
    double n = (M * G * 5) / (R * T0);
    
    double pH = P0 * exp(-n);
    double p = (pH * M) / (R * (T0 + airtemp_h));
    double tas = (airspeed_kmh + dV) / sqrt(p / p0);

    printf("n = %lf\npH = %lf\np = %lf\np / p0 = %lf\ntas = %lf\n", n, pH, p, (p / p0), tas);
    
    return 0;
}