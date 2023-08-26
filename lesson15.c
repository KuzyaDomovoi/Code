#include <stdio.h>

int main(void)
{
    unsigned char var = 153; //binary notation 10011001;
    unsigned char not_var = ~var; //result: 01100110 (number 102);

    printf("var = %d, not_var = %d\n", var, not_var);

    return 0;
}

//  153 + 102 = 255;

//  10011001 (153)
// +
//  01100110 (102)
// =
//  11111111 (255)
