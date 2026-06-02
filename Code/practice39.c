#include <stdio.h>

int main(void)
{
    int ar_1[50] = {8, 4, 1, 3, 5, 7, 9, 5, 2, 0, 4, 2, 6};
    int ar_2[25];

    int size_1 = sizeof(ar_1) / sizeof(ar_1[0]);
    int size_2 = sizeof(ar_2) / sizeof(ar_2[0]);
    int size = (size_1 > size_2) ? size_1 : size_2;
    
    for(int i = 0; i < size; ++i)
        ar_2[i] = ar_1[i];
    for(int i = 0; i < size; ++i)
        printf("%d ", ar_2[i]);

    return 0;
}
