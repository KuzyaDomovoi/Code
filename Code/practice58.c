#include <stdio.h>
#define COLS 3

void show_ar1D_to_ar2D(int *arr, int size) {
    for (int i = 0; i < size; ++i) { 
        printf("%d %c", arr[i], (i + 1) % COLS ? '\t' : '\n');
    }
}

int main(void) 
{
    int ar[] = {1, 2, 3, 4, 5, 6, 7};
    show_ar1D_to_ar2D(ar, sizeof(ar) / sizeof(*ar));

    return 0;
}
