#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 7.5, b = -3.43;
    /*if(a > b)
        max_ab = a;
    else
        max_ab = b;
    */    
    
    double max_ab = a > b ? a : b; //double max_ab = (a > b) ? a + 2 : b - 5;
    printf("max_ab = %.2f\n", max_ab);

    double res_abs = (a < b) ? fabs(a) : fabs(b);
    printf("res_abs = %.2f\n", res_abs);

    int c = 8;
    printf("c = %d is %s digit\n", c, (c % 2 == 0) ? "even" : "odd");
    
    /*int x = 2, y = 3, z = -4;
    int max_xyz = (x > y) ? (x > z ? x : z) : (y > z) ? y : z;
    printf("max_xyz = %d\n", max_xyz);
    */
   
    return 0;
}
