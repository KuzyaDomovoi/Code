#include <stdio.h>

int main(void)
{
    unsigned char var = 153; //binary notation 10011001;
    unsigned char not_var = ~var; // ~ (invert), result: 01100110 (number 102);
    //  153 + 102 = 255:
    //  10011001 (153)
    // +
    //  01100110 (102)
    // =
    //  11111111 (255);
    printf("var = %d, not_var = %d\n", var, not_var);
       
    unsigned char flags = 5;     //     00000101
                                 // &(*)
    unsigned char mask = 4;      //     00000100
                                 //    = 
    unsigned res = flags & mask; //     00000100;
    //flags & mask (and) (*)
    //  0 * 0 = 0;   
    //  0 * 1 = 0;
    //  1 * 0 = 0;
    //  1 * 1 = 1;
    printf("res = %d\n", res);
    if((flags & mask) == mask)
        printf("bit 2 is on\n");
    else
        printf("bit 2 is off\n");

    flags = flags & ~mask; //     00000101 (5) flags
                           // &(*)     
                           //     11111011 (251) <- (~00000100) (4) mask
                           //    = 
                           //     00000001 (1) res;
    printf("flags = %d\n", flags);

    unsigned char flags_1 = 8; //00001000;
    unsigned char mask_1 = 5;  //00000101;

    flags_1 = flags_1 | mask_1; // | (or) (+);
    printf("flags_1 = %d\n", flags_1);
    //     00001000
    // |(+)
    //     00000101
    //    =
    //     00001101;

    return 0;
}
