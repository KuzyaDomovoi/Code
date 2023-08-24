#include <stdio.h>

int main(void)
{
    unsigned int price = 0;
    double wight = 0.0;

    int res = scanf("%*u; %u; %lf", &price, &wight);

    printf("res = %d: price = %d, wight = %.2f\n", res, price, wight);

    return 0;
}
