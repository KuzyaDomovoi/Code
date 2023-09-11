# include <stdio.h>

double per_sq(double, double); // func prototype (func.c) names of params can be omitted;

int main(void)
{
    printf("per = %.2f\n", per_sq(2.5, 3.5));
    return 0;
}
