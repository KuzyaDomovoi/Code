#include <stdio.h>

int main(void)
{
    short g = 4, d = 1;
    short *ptr = &g;
    short *p = &d;
    
    printf("ptr = %u, p = %u\n", ptr, p);
    // ptr = 34758224, p = 34758226;

    /*Pointers can not be multiplied, divided or added 
    (ptr += p; : error: invalid operands to binary +...),
    but they can be subtracted only:*/

    int res = ptr - p; // res = -1;
    /* is subtraction result of two memory
    cells and division by number of memory cells occuped
    by the variable (number of bytes (in this case = 2));
    res = (34758224 - 34758226) / 2 = -1; 
    '1' - is an amount of elements between the pointers;*/

    printf("res = %d\n", res);
    
    return 0;
}
