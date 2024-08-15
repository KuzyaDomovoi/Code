#include <stdio.h>

int main(void)
{
    int g = 476789; //476789 = 117 + 256^1 * 70 + 256^2 * 7;
    char *ptr = (char *)&g; /*if type 'char' - reading the
    first memory cell only from the variable's address.*/

    for(int i = 0; i < sizeof(int); ++i) /* iterate over
    all memory cells from the variable's address.*/
        printf("%d ", *ptr++); // the postfix form '*(ptr++)' unary operations preority;
        //ptr++; 
        /*If the prefix form '*++ptr', than increment 
        operation is perfomed first and than the 
        deference operation.*/

    int f = 476789;
    int *p = &f;
    *p += 1;
    printf("\nf = %d\n", f); // f = 47690;

    int h = 476789;         // 117 + 256^1 * 70 + 256^2 * 7;
    char *d = (char *)&h;   // 117, 70, 7, 0;
    int x = *d + 1;         // 117 + 1;
    printf("\nh = %d, x = %d\n", h, x);     // h = 476789, x = 118;

    int j = 476789;         // 117 + 256^1 * 70 + 256^2 * 7;
    char *k = (char *)&j;   // 117, 70, 7, 0;
    int y = *(k + 1);       // 70;
    printf("\nj = %d, y = %d\n", j, y);     // j = 476789, y = 70;

    int l = 476789;         // 117 + 256^1 * 70 + 256^2 * 7;
    char *b = (char *)&l;   // 117, 70, 7, 0;
    int z = (*b)++;         // 117;
    printf("\nl = %d, z = %d\n", l, z);     // l = 476790, z = 117
    return 0;
}
