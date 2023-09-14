#include <stdio.h>
#define SIZE 6

void filter(int dst[], size_t size_dst, 
            const int src[], size_t size_src,
            int (*is_correct)(int))
/*int dst[] with its size 'size_t size_dst' is an array
where even values will be placed;
const int src[] with its size 'size_t size_src' is an
array from which these even values will be transferred;
int (*is_correct)(int) is a pointer to func, that will
logically select desired elements from an array*/
{
    for(int i = 0; i < size_dst; ++i) 
        dst[i] = 0; // reset to '0' all elements of array 'int dst[]' in the func filter;
    for(int i = 0, j = 0; i < size_src; ++i) // j = 0 is an auxiliary counter for array's iteration 'int dst[]';
        if(is_correct(src[i])) // selecting elements from array int src[i] (if = 0 is even) that will satisfy the conditions of func is_correct();
            dst[j++] = src[i];
}

int is_even(int x) // is a func to which refers the pointer '*is_correct()';
{
    return x % 2 == 0; // for if(is_correct(src[i]));
}

int is_positive(int x)
{
    return x > 0;
}

int is_odd(int x)
{
    return x % 2 != 0;
}

int main(void)
{

// Pointer to funcs:

    int digits[] = {-3, 4, 10, 11, -5, 3};
    int (*criterials[])(int) = {is_even, is_odd, is_positive};
    int result[SIZE];
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), is_even);
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);
    
    putchar('\n');

    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), is_positive);
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    putchar('\n');

    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), is_odd);
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    putchar('\n');

// Pointer to arrays:

    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), criterials[1]);
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    return 0;
}
