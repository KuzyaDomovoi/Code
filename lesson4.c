#include <stdio.h>

int main(void)
{
    short y = -5;
    int z = 10;

    double res_1 = (double)y / (double)z;
    double res_2 = 7.0 / 2.0;
    printf("res_1 = %.2f, res_2 = %.2f\n", res_1, res_2);

    short a = -5, b = 7, c = 4;
    double D = b * b - 4 * a * c;
    printf("%.f\n", D);

    double res_3 = 5.0 / (3.0 * 2.0);
    int p = 2 * (b + c);
    printf("res_3 = %.2f, p = %d\n", res_3, p);

    double height, lenght;
    int result = scanf("%lf %lf", &height, &lenght);
    if(result != 2) {
        printf("Error");
        return 0;
    }

    double sq = height * lenght / 2.0; //triangle area;
    printf("%.2f\n", sq);

    return 0;
}
