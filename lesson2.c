#include <stdio.h>

int main(void)
{
    char byte1 = '0', byte2 = '0';

    int res = scanf("%c %c", &byte1, &byte2);

    printf("res = %d, byte1 = %c, byte2 = %c\n", res, byte1, byte2);

    return 0;
}
