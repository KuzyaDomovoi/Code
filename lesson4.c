#include <stdio.h>

int main(void)
{
    short y = -5;
    int z = 10;

    double res_1 = (double)y / (double)z;
    double res_2 = 7.0 / 2.0;

    short a = -5, b = 7, c = 4;
    double D = b * b - 4 * a * c;

    double res_3 = 5.0 / (3.0 * 2.0);
    int p = 2 * (b + c);

    double height, lenght;
    int result = scanf("%lf %lf", &height, &lenght);
    if(result != 2) {
        printf("Error");
        return 0;
    }

    double sq = height * lenght / 2.0;
    printf("%.2f\n", sq);

    return 0;
}
