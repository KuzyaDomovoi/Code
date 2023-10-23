#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <math.h>

int main(void)
{
    //srand(time(NULL));
    //int range = 10;
    //int r_1 = rand() % range; // [0; range];
    //int r_2 = rand() % range - 5; // [-5; range - 5];
    //int r_3 = rand() + rand();
    //double range_float = (double)rand() / (double)RAND_MAX; // [0; 1];
    //printf("%d, %d, %d, %.2f\n", r_1, r_2, r_3, range_float);

    // ax² + bx + c = 0;
    // D = b² - 4ac;
    // x1 = -(b + sqrt(D)) / (2 * a);
    // x2 = -(b - sqrt(D)) / (2 * a);
    double a, b, c;
    double D, x1, x2;
    if(scanf("%lf, %lf, %lf", &a, &b, &c) != 3) {
        printf("Error input\n");
        return 0;
    }
    
    D = b * b - 4 * a * c;
    if(D < 0) {
        printf("D = %.2f < 0\n", D);
        return 0;
    }

    D = sqrt(D);
    x1 = -(b + D) / (2.0 * a);
    x2 = -(b - D) / (2.0 * a);
    printf("x1 = %.2f, x2 = %.2f\n", x1, x2);

    double res_1 = sin(x1);
    double res_2 = sin(2 * x1);
    double res_3 = sin(10.0 / 15.0);
    printf("res_1 = %.2f, res_2 = %.2f, res_3 = %.2f\n", res_1, res_2, res_3);
    
    return 0;
}
