#include <stdio.h>
#define COLS 3
#define ROWS 3

void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { 
        printf("%d %c", arr[i], (i + 1) % COLS ? '\t' : '\n');
    }
}

void array_to_matrix(int *matrix, int *arr, int row, int col) {
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            arr[i * col + j] = *(matrix + i * col + j);
        }
    }
}

int main(void) 
{
    int matrix[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ar[COLS * ROWS] = {0};
    array_to_matrix((int *)matrix, ar, ROWS, COLS);
    print_array(ar, COLS * ROWS);
    return 0;
}
