#include <stdio.h>

int main(void)
{
    short g = 4, d = 1;
    short *ptr = &g;
    short *p = &d;
    
    printf("ptr = %u, p = %u\n", ptr, p);
    // ptr = 34758224, p = 34758226;

    /*Pointers can't be multiplied, divided or added 
    (ptr += p; : error: invalid operands to binary +...),
    but they can be subtracted only:*/

    int res = ptr - p; // res = -1;

    printf("res = %d\n", res);
    
    return 0;
}
