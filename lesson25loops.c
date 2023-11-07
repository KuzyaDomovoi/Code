#include <stdio.h>

int main(void)
{
    int pass_code = 3;
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

    for(int i = 1; i <= total_boxes; ++i)
        for( int j = 1; j <= total_files; ++j)
            printf("Box %d, file %d\n", i, j);

    return 0;
}
