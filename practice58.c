#include <stdio.h>
#define COLS 3
#define ROWS 3

void array_to_matrix(int *matrix, int *arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i * cols + j] = *(matrix + i * cols + j);
        }
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; ++i) { 
        printf("%d %c", arr[i], (i + 1) % COLS ? '\t' : '\n');
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
