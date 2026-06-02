#include <stdio.h>

int main(void)
{
// Statement 'break':

    double x, sum_1 = 0.0;
    while(scanf("%lf", &x) == 1 && x > 0) {
    //    if(x < 0)
    //        break; 
    /*The 'break' statement is used to prematurely 
    breaking only current loop statement and transfer to
    the next statment within the current function ('main').
    The 'return' statement is used to break the call 
    to the current function. That is it can break any
    subsequent statment within the current function.*/
        sum_1 += x;
    }
    printf("sum_1 = %.2f\n", sum_1);

// Statment 'continue':

    int y, sum_2 = 0;
    while(scanf("%d", &y) == 1 && y != 0) {
        if(y % 2 == 0)
            continue;
    /*The statement 'continue' is used to skip all
    subsequent operations within the current iteration and 
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

// Statement 'goto':

    int s = 0;
    for(int i = 1; i <= 10; ++i)
        for(int j = 7; j >= 5; --j) {
            if( i - j > 0)
                goto exit_sum; //break, return;
    /*The 'goto' statement is used to break all nested
    loop statements ('for') and transfer to the specified
    lable ('exit_sum').
    Using the 'break' statement hier allows to break only 
    internal loop statement and all external loop 
    tatements remain in operation.
    Using the 'return' statement hier allows to break all 
    nested loop statement, but the current function ('main')
    is also breaked.
    ! The frequent use of the 'goto' statement makes the
    progtamm more difficult to read und edit. And at 
    the compile time the executable code will not be 
    optimazed for fast execution on the current computer
    architecture.*/
            s += i - j;
        }
    exit_sum: printf("s = %d\n", s);

    return 0;
}
