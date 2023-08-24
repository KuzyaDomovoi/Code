#include <stdio.h>

int main(void)
{
    char byte1 = '0', byte2 = '0';

    int count = scanf("%c %c", &byte1, &byte2);

    printf("count = %d, byte1 = %c, byte2 = %c\n", count, byte1, byte2);

    return 0;
}
