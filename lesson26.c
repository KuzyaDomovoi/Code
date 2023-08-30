#include <stdio.h>

int main(void)
{
    double x, sum_1 = 0.0;
    while(scanf("%lf", &x) == 1 && x > 0) {
    //    if(x < 0)
    //        break; 
    /*The statment 'break' is used to prematurely 
    termination only the current loop and transfers to 
    the next statment within the current function ('main').
    The statement 'return' is used to terminate 
    the call to the current function. That is it can 
    interrupt any subsequent statment within the current 
    function.*/
        sum_1 += x;
    }
    printf("sum_1 = %.2f\n", sum_1);

    int y, sum_2 = 0;
    while(scanf("%d", &y) == 1 && y != 0) {
        if(y % 2 == 0)
            continue;
    /*The statement 'continue' is used to skip the all
    subsequent oparations within the current iteration and 
    transfer to top of the current loop.*/
        sum_2 += y;
    }
    printf("sum_2 = %d\n", sum_2);

    //for(int i = 1; i <= 100; ++i) {
    //    if(i % 3 != 0 || i % 5 != 0)
    //        continue;
    //    printf("%d ", i); // 15 30 45 60 75 90;
    //}
    for(int i = 1; i <= 100; ++i) {
        if(i % 3 == 0 && i % 5 == 0)
            printf("%d ", i);
    }

    return 0;
}
