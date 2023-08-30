#include <stdio.h>

int main(void)
{
    char d = 10; // for data type 'char': 10 (is an assignment operation the value '10' to the variable 'd' and it is written to one memory cell only (1 byte));
    char *gpt = &d; // gpt = &d is an operation of initialization, not assignment operation!;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    *gpt = 100; // char: 100;
    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    
    int c = 10; // for data type 'int': 10 = 10 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0 (is written sequentially to four memory cell (4 bytes));
    int *gpt = &c;

    printf("gpt = %p, *gpt = %d, c = %d\n", gpt, *gpt, c);

    *gpt = 75432; // int: 75432 = 168 + 256^1 * 38 + 256^2 * 1 + 256^3 * 0;
    //*gpt = 1; // int: 1 = 1 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0;
    printf("gpt = %p, *gpt = %d, c = %d\n", gpt, *gpt, c);

    return 0;
}
