#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int pass_code = rand() % 10;
    int enter_code;
    int c;

    do {
        printf("Enter pass code: ");
        scanf("%d", &enter_code);
        while ((c = getchar()) != '\n' && c != EOF)
            { }
    } while (enter_code != pass_code);

    printf("Access is allowed\n");

    int total_boxes = 3;
    int total_files = 6;

    for(int i = 0; i < total_boxes; ++i)
        for( int j = 0; j < total_files; ++j)
            printf("Box %d, file %d\n", i + 1, j + 1);

    return 0;
}
