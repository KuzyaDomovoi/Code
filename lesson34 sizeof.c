#include <stdio.h>

#define TOTAL_MARKS 13

int main(void)
{
    int marks[TOTAL_MARKS];

    marks[2] = 4; // put the number 4 to third array element[indexes beginning from 0; 1; 2; ... ]; 
    marks[0] = 2 * 3;
    marks[12] = 7 - 2; //put the 5 (7 - 2) to the last array element[last element is 12 (13 - 1)];
    //marks[13] = 1; //!error! Arrays are the most often a source of some errors;

    size_t bytes_marks = sizeof(marks);
    size_t size_marks = sizeof(marks) / sizeof(marks[0]); //marks[0] = (*marks);

    printf("%zu, %zu\n", bytes_marks, size_marks);

    int x = marks[2]; // 4;
    printf("x = %d\n", x);

    for(int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);

    return 0;
}
