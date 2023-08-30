#include <stdio.h>

int main(void)
{
    char d = 10; // for data type 'char': 10 (is recorded only to one memory cell (1 byte));
    char *gpt = &d; // gpt = &d is an operation of initialization, not assignment operation!;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    *gpt = 100; // char: 100;
    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    
    int d = 10; // for data type 'int': 10 = 10 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0 (is recorded sequentially to four memory cell (4 bytes));
    int *gpt = &d;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    *gpt = 75432; // int: 75432 = 168 + 256^1 * 38 + 256^2 * 1 + 256^3 * 0;
    //*gpt = 1; // int: 1 = 1 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0;
    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    return 0;
}
