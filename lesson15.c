#include <stdio.h>

int main(void)
{
    unsigned char var = 153; //binary notation 10011001;
    unsigned char not_var = ~var; //result: 01100110 (number 102);

    //  153 + 102 = 255;
    //  10011001 (153)
    // +
    //  01100110 (102)
    // =
    //  11111111 (255);

    printf("var = %d, not_var = %d\n", var, not_var);

    unsigned char v_1 = 5;
    unsigned char v_2 = 4;
    
    unsigned res = v_1 & v_2;
    printf("%d\n", res);

    return 0;
}
