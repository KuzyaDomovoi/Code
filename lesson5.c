#include <stdio.h>

int main(void)
{
    int res = 10 % 4; // int res = 10 - 10 / 4 * 4;
    int res1 = -10 % 4;
    int res2 = -10 % -4;
    int res3 = 10 % -4;

    int digit;
    scanf("%d", &digit);
    printf("digit %d is %s\n", digit, (digit % 2) == 0 ? "even" : "odd");

    int res4 = digit % 2;

    int range = 10; //[0; range-1];
    int res5 = digit % range;
    
    printf("res = %d, res1 = %d, res2 = %d, res3 = %d\nres4 = %d\nres5 = %d\n", res, res1, res2, res3, res4, res5);

    return 0;
}
