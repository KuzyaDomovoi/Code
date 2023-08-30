#include <stdio.h>

int main(void)
{
    double x, s = 0.0;
    while(scanf("%lf", &x) == 1 && x > 0) {
    //    if(x < 0)
    //        break; 
    /*The statment 'break' is used to prematurely 
    terminatation only the current loop 'while' and
    transfers to the next statment.
    But if the statement 'return' is used, the call to the 
    current funktion 'main' is terminated. That is it can 
    interrupt any following statment within the current 
    function.*/  
        s += x;
    }
    printf("s = %.2f\n", s);

    return 0;
}
