#include <stdio.h>
#include "func.h" // to connecting an own head-file is used the double quotes;

//double per_sq(double, double); // func prototype (func.c) names of params can be omitted;

int main(void)
{
    abs_int(-5);
    sq_to_int(-5.5);    
    printf("per = %.2f\n", per_sq(2.5, 3.5));
    return 0;
}
