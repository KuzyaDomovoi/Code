#include <stdio.h>

int main(void)
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};

    
    for(int i = 0; i < sizeof(ar) / sizeof(*ar); ++i)
        printf("%d ", *(ar + i)); // 4 3 2 1 5 6 7;
    
    printf("\n");

    short *ptr_ar;
    ptr_ar = ar;
    short x = *ptr_ar;
    *(ptr_ar + 1) = -3;
     
    short z = ptr_ar[2];

    printf("z = %d\n", z);

    return 0;
}
