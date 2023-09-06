#include <stdio.h>

int main(void)
{
// Bit operation '~' (not == inverting):

    unsigned char var = 153; //binary num notation is 10011001;
    unsigned char not_var = ~var; //invert result == 01100110 (decimal num notation is 102);
    //   153 + 102 = 255:
    //   10011001 (153)
    //  +
    //   01100110 (102)
    // ==
    //   11111111 (255);
    printf("var = %d, not_var = %d\n", var, not_var);

// Bit opetation '&' (and == *):

    unsigned char flags = 5;     //     00000101
                                 // &(*)
    unsigned char mask = 4;      //     00000100
                                 //   == 
    unsigned res = flags & mask; //     00000100;
    //  & (and) (*):
    //  0 * 0 == 0;   
    //  0 * 1 == 0;
    //  1 * 0 == 0;
    //  1 * 1 == 1;
    printf("res = %d\n", res);
    if((flags & mask) == mask)
        printf("bit 2 is on\n");
    else
        printf("bit 2 is off\n");

    //flags = flags & ~mask == flags &= ~mask;
    flags &= ~mask; //     00000101 (5) flags
                           // &(*)     
                           //     11111011 (251) <- (~00000100) (4) mask
                           //   == 
                           //     00000001 (1) res;
    printf("flags = %d\n", flags);

// Bit operation '|' (or == +):

    unsigned char flags_1 = 9; // 00001000;
    unsigned char mask_1 = 5;  // 00000101;
    //flags_1 = flags_1 | mask_1 == flags_1 |= mask_1;
    flags_1 |= mask_1; // | (or) (+);
    //     00001001 (9)
    // |(+)
    //     00000101 (5)
    //   ==
    //     00001101 (13);
    printf("flags_1 = %d\n", flags_1);


// Bit operation '^' (exclusive 'or' - XOR):

    unsigned char flags_2 = 9; // 00001001;
    unsigned char mask_2 = 1;  // 00000001;
    //flags_2 = flags_2 ^ mask_2 == flags_2 ^= mask_2;    0 ^ 0 == 0;
    flags_2 ^= mask_2;                                 // 0 ^ 1 == 1;
    flags_2 ^= mask_2;                                 // 1 ^ 0 == 1;
    //   00001001 (9)                                     1 ^ 1 == 0;
    //  ^                           
    //   00000001 (1)               
    // ==
    //   00001000 (8);
    printf("flags_2 = %d\n", flags_2);
    
// Bit operations '>>' and '<<' (shift):

    unsigned char x = 40;       // 00101000;
    printf("x = %d\n", x);
    //x >>= 1 == x = x >> 1;
    x >>= 1;                    // 00101000 (num 20) (40 // (2** 1));
    printf("x = %d\n", x);
    x >>= 2;                    // 00101000 (num 5) (20 // (2 ** 2));
    printf("x = %d\n", x);
    x >>= 1;                    // 00000010 (num 2) (5 // (2 ** 1));
    printf("x = %d\n", x);
    x >>= 1;                    // 00000001 (num 1) (2 // (2 ** 1));
    printf("x = %d\n", x);
    x <<= 1;                    // 00000010 (num 2) (1 * (2 ** 1));
    printf("x = %d\n", x);
    x <<= 2;                    // 00001000 (num 8) (2 * (2 ** 2));
    printf("x = %d\n", x);

    signed char y = -128;    // 1000 0000;
    printf("y = %d\n", y);
    y <<= 1;                 // 0000 0000 (num 0); (-128 * (2 ** 1));
    printf("y = %d\n", y);
    y = -128;                // 1000 0000;
    y >>= 1;                 // 1100 0000 (num -64) (-128 // (2 ** 1));
    printf("y = %d\n", y);

/*!The priorety of bit shift operations '>>' and '>>' are equal, but higher than 
compar operations and lower than math opetrations!*/

    return 0;
}

// Opetations priorety:
// 1. ~ (not) so is ia an unary oparation;
// 2. & (and) binary;
// 3. ^ (XOR) binary;
// 4. | (or)  binary;
