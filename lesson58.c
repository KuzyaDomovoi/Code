#include <stdio.h>

int sq_rect(int wigth, int height)
{
    return wigth * height;
}

int per_rect(int wigth, int height)
{
    return 2 * (wigth + height);
}

void print_hi(void)
{
    puts("Hi!");
}

int main(void)
{
    int (*ptr_func)(int, int); // declarate the pointer '*ptr_func' which is refers to any func with integer params and returns datatype 'int';
    ptr_func = sq_rect;
    int sq = ptr_func(2, 3);
    printf("sq = %d\n", sq);

    int (*ptr_func_1)(int, int);
    ptr_func_1 = per_rect;
    int per = ptr_func_1(2, 3);
    printf("per = %d\n", per);

    void (*ptr_hi)(void);
    ptr_hi = print_hi;
    ptr_hi();

    printf("sq_rect = %p\n", sq_rect); // the funcname 'sq_rect' is an pointer to its address here;
    printf("per_rect = %p\n", sq_rect); // addresse of func;
    return 0;
}
