#include <stdio.h>

int main(void)
{
    short g = 4, d = 1;
    short *ptr = &g;
    short *p = &d;
    
    printf("ptr = %u, p = %u\n", ptr, p);

    int res = ptr - p; // 

    printf("res = %d\n", res);
    
    return 0;
}
