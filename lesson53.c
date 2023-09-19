#include <stdio.h>
#include <math.h> // to use funcs: pow() and NAN;

// continuation of topic Functions:

double sq4_x(double x) 
/* if a func has data type 'void' the statement 'return'
is not required;*/
{
    if(x < 0)
        return NAN; // is Not A Number;
    //return pow(x, 0.25);
    return x;
    /* since the func has data type
    'double' the statement return is required, the func
    further ends and no more statements in the current
    func body are executed;*/
}

void print_even_x(int x)
/* the func has data type 'void' the statement 'return'
in not required;*/
{
    if(x % 2 != 0)
        return; /* the statment 'return;' nothing
        returned but completes the current func;*/

    printf("x = %d\n", x); 
}

int main(void)
{
    printf("%f\n", sq4_x(-25));
    
    print_even_x(4);
    print_even_x(5);
    
    return 0;
}
