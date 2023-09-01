#include <stdio.h>
#include <stdlib.h>

#define TOTAL_MARKS 13

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int val = -5;    
    int marks[TOTAL_MARKS] = {1, 2, 3, 4, val, abs(val), 0}; //array initialization, not declaration;
    marks[10] = 10;
    for(int i = 0; i < sizeof(marks) / sizeof(marks[0]); ++i)
        printf("%d ", marks[i]); // 1 2 3 4 -5 5 0 0 0 0 10 0 0;
    


    return 0;
}
