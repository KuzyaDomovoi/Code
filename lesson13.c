#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 7.5, b = -3.43;
    double max_ab = a > b ? a : b;
    //double max_ab = (a > b) ? a + 2 : b - 5;

    /*if(a > b)
        max_ab = a;
    else
        max_ab = b;
    */
    
    double res_abs = (a < b) ? fabs(a) : fabs(b);

    int z = 8;
    printf("z = %d is %s digit\n", z, (z % 2 == 0) ? "even" : "odd");
    
    printf("max_ab = %.2f\n", max_ab);
    printf("res_abs = %.2f\n", res_abs);
        
    return 0;
}
