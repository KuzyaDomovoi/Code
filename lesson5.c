#include <stdio.h>

int main(void)
{
    int res = 10 % 4; // int res = 10 - 10 / 4 * 4;
    int res1 = -10 % 4;
    int res2 = -10 % -4;
    int res3 = 10 % -4;

    int digit;
    if(scanf("%d", &digit) % 2 == 0)
        printf("digit %d is even\n", digit);
    else
        printf("digit %d is odd\n", digit);
    int res4 = digit % 2;

    int range = 10; //[0; range-1];
    int res5 = digit % range;
    
    printf("res = %d, res1 = %d, res2 = %d, res3 = %d\nres4 = %d\nres5 = %d\n", res, res1, res2, res3, res4, res5);

    return 0;
}
