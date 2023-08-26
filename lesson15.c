#include <stdio.h>

int main(void)
{
// Binary operation '~' (inverting):

    unsigned char var = 153; //binary num notation is 10011001;
    unsigned char not_var = ~var; //invert result == 01100110 (decimal num notation is 102);
    //  153 + 102 = 255:
    //  10011001 (153)
    // +
    //  01100110 (102)
    // =
    //  11111111 (255);
    printf("var = %d, not_var = %d\n", var, not_var);

// Binary opetation '&' (and) == (*):

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

// Binary operation '|' (or) (+):

    unsigned char flags_1 = 9; //00001000;
    unsigned char mask_1 = 5;  //00000101;
    flags_1 = flags_1 | mask_1; // | (or) (+);
    //     00001001 (9)
    // |(+)
    //     00000101 (5)
    //    =
    //     00001101 (13);
    printf("flags_1 = %d\n", flags_1);


// Binary operation '^' (exclusive 'or' - XOR):

    unsigned char flags_2 = 9; //00001001;
    unsigned char mask_2 = 1;  //00000001;
    flags_2 = flags_2 ^ mask_2;
    //   00001001 (9)
    //  ^
    //   00000001 (1)
    //  =
    //   00001000 (8);
    printf("flags_2 = %d\n", flags_2);
    
    return 0;
}
