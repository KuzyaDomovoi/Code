#include <stdio.h>

int main(void)
{
    int code = 0;
    int price = 0;
    double wight = 0.0;

    int res = scanf("%u, %u, %lf", &code, &price, &wight);

    printf("res = %d: code = %u, price = %u, wight = %f\n", res, code, price, wight);

    return 0;
}
