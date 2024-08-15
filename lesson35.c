#include <stdio.h>
#include <stdlib.h>

#define TOTAL_MARKS 13
#define TOTAL_CORRDS 10

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int val = -5;    
    int marks[TOTAL_MARKS] = {1, 2, 3, 4, val, abs(val), 0}; //array initialization, not declaration;
    marks[10] = 10;
    for(int i = 0; i < sizeof(marks) / sizeof(marks[0]); ++i)
        printf("%d ", marks[i]); // 1 2 3 4 -5 5 0 0 0 0 10 0 0;
    
    printf("\n");
    
    int corrds[TOTAL_CORRDS] = {10, -2, 30};
    for(int j = 0; j < sizeof(corrds) / sizeof(corrds[0]); ++j)
        printf("%d ", corrds[j]); // 10 -2 30 0 0 0 0 0 0 0;
    
    printf("\n");
    
    short digits[10] = {-1, [2] = 5, 18, [9] = -1}; 
    for(int k = 0; k < sizeof(digits) / sizeof(digits[0]); ++k)
        printf("%d ", digits[k]); // -1 0 5 18 0 0 0 0 0 -1;

    return 0;
}
