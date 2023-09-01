#include <stdio.h>

int main(void)
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};
    short *ptr_ar;

    ptr_ar = ar;
    
    short z = ptr_ar[2];

    return 0;
}
