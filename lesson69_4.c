#include <stdio.h>

#define PTR_INT int*

int is_even(int x)
{
    return x % 2 == 0;
}

typedef int (*PTR_EVEN)(int);
typedef char (*PTR_AR_2D)[4];

int main(void)
{
   char ar_2d[5][4] = {0};
   PTR_AR_2D ptr_2d = ar_2d;

   PTR_EVEN func_even = is_even;
   
   ptr_2d[1][2] = 5;

   printf("%d\n", func_even(2));
   printf("%d\n", func_even(3));

   printf("%d\n", ptr_2d[1][2]);

    return 0;
}
