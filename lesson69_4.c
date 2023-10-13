#include <stdio.h>

#define PTR_INT int*

int is_even(int x)
{
    return x % 2 == 0;
}

typedef int (*PTR_EVEN)(int);

typedef char (*PTR_AR_2D)[4]; // pointer to array ar_2d;

int main(void)
{
    PTR_EVEN func_even = is_even;

    printf("%d\n", func_even(2)); // == 1 (true) - is even;
    printf("%d\n", func_even(3)); // == 0 (false) - is odd;

    char ar_2d[5][4] = {0};
    PTR_AR_2D ptr_2d = ar_2d;
    ptr_2d[0][1] = 5;
   
    printf("%d\n", ptr_2d[0][1]); // 5;

    return 0;
}
