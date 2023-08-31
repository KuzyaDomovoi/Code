#include <stdio.h>

int main(void)
{
    short g = 4, d = 1;
    int *ptr = &g;

    printf("ptr = %u\n", ptr);

    --ptr;
    ++ptr;

    ptr += 3;
    ptr -= 4;
    ptr = ptr + 10;
    ptr = ptr - 9;

    printf("ptr = %u\n", ptr);
    
    return 0;
}
