#include <stdio.h>

// continuation of topic Functions:

double min_2(double a, double b)
{
    return(a < b) ? a : b;
}

double min_3(double a, double b, double c)
{
    double min_ab = min_2(a, b);
    return(min_ab < c) ? min_ab : c;
}

int main(void)
{
    int x = 1, y = -2, z = 10;
    double res_1 = min_2(x, y);
    double res_2 = min_3(x, y, z);
    double res_3 = min_2(min_2(x, y), z);
    double res_4 = min_2(x, min_2(y, z));
    
    double res_5 = min_2(min_2(-2, 3), min_2(x, y));
    double res_6 = min_2(min_2(-2, 3), min_3(x, y, z));
    
    //double res_7 = min_2(++x, x);
    //double res_8 = min_2(x, ++x);
    //double res_9 = min_2(y, x++); // x = 1 get to fun and than x++ (x = 3) for next operation;
    double res_10 = min_2(y, ++x); // x++ (x = 3) and than x = 3 get to fun;

    printf("res_1 = %.2f, res_2 = %.2f, res_3 = %.2f, res_4 = %.2f\n", 
            res_1, res_2, res_3, res_4);

    //printf("res_7 = %.2f\n", res_7); // 1
    //printf("res_8 = %.2f\n", res_8); // 2
    //printf("res_9 = %.2f\n", res_9); // -2
    printf("res_10 = %.2f\n", res_10); // -2

    return 0;
}
