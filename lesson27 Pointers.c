#include <stdio.h>

int main(void)
{
    /*Pointers are designed to write and read data from any
    memory cells and store theirs addresses with data.
    They are denoted witn the sign '*', for example, as
    'char *gpt' and divided into the following variable types:
        char *gpt;   (memory area - 1 byte),
        int *gpt;    (memory area - 4 bytes),
        double *gpt; (memory area - 8 bytes).
    The pointers in OSx86 - is allocated 4 bytes of memory;
                 in OSx64 - is allocated 8 bytes of memory.
    Pointer notation construction:
        chat d = 10;        memory allocation operation for the variable 'd';
        char *gpt;          declaration of pointer for working with data type 'char';
        gpt = &d;           assignment operation of value 'd' to pointer 'gpt';
        char x = *gpt;      value read operation from memory cell of variable 'd';
        *gpt = 100;         value write operation to memory cell of variable 'd';
        short *a, *b, *c;   declaration of 3 pointers in one data type.*/

    char d = 10;    // for data type 'char': 10 (is an assignment operation the value '10' to the variable 'd' and it is written to one memory cell only (1 byte));
    char *gpt = &d; // gpt = &d is an initialization not assignment !;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    *gpt = 100; // char: 100;
    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    int f = 10; // for data type 'int': 10 = 10 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0 (is written sequentially to four memory cell (4 bytes));
    int *gpd = &f;

    printf("gpt = %p, *gpt = %d, f = %d\n", gpd, *gpd, f);

    *gpd = 75432; // int: 75432 = 168 + 256^1 * 38 + 256^2 * 1 + 256^3 * 0;
    //*gpt = 1; // int: 1 = 1 + 256^1 * 0 + 256^2 * 0 + 256^3 * 0;
    printf("gpt = %p, *gpd = %d, f = %d\n", gpd, *gpd, f);

    return 0;
}
