#include <stdio.h>

int main(void)
{
    double x, s = 0.0;
    while(scanf("%lf", &x) == 1 && x > 0) {
    //    if(x < 0)
    //        break; 
    /*The statment 'break' terminates only the current 
    loop 'while' (in the current function 'main') and 
    transfers to the next statment.
    But if the statement 'return' is used, the current 
    funktion 'main' is terminated.*/
        s += x;
    }
    printf("s = %.2f\n", s);

    return 0;
}
