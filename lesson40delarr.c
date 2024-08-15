#include <stdio.h>

#define TOTAL_MARKS 10

int main(void)
{
    int marks[TOTAL_MARKS] = {3, 2, 4, 5, 2, 4};
    int delete_index = 3;
    
    for(int i = delete_index; i < TOTAL_MARKS - 1; ++i) {
        marks[i] = marks[i + 1];
        printf("marks[%d] = marks[%d]\n", i, i + 1);
    }

    for(int i = 0; i < TOTAL_MARKS; ++i)
    printf("%d ", marks[i]); // 3 2 4 2 4 0 0 0 0 0;

    return 0;
}
