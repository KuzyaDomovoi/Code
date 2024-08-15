#include <stdio.h>
#include "func.h" /* to connecting an own head-file is 
used here the double quotes;*/

//double per_sq(double, double); 
//int abs_int(int x);
//int sq_to_int(double x);

/* the func prototypes are inserted in extra file 'func.h',
witch bodies are registred in extra file 'func.c';
their params names can be omitted;*/

int main(void)
{
    printf("per = %.2f\n", per_sq(2.5, 3.5));
    printf("abs = %d\n", abs_int(-5));
    printf("sq = %d\n", sq_to_int(-5.5));    
    
    return 0;
}
