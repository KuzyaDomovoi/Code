#include <stdio.h>
#define COLS 4

void show_ar1Dto2D(const short (*ar), int length)
{
    int res_ij;
    int rows = (length + (COLS - 1)) / COLS;
    for(int i = 0; i < rows; ++i) { // (i <= length / COLS);
        for(int j = 0; j < COLS && i * COLS + j < length; ++j) {
            res_ij = ar[i * COLS + j];
            printf("%d ", res_ij);
        }
        putchar('\n');
    }   
}

int main(void)
{
    short ar[] = {1, 2, 3, 4, 5, 6};
    show_ar1Dto2D(ar, sizeof(ar) / sizeof(*ar));

    return 0;
}
