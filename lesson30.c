#include <stdio.h>

int main(void)
{
// Address arithmetic:

/*The pointer value is changed to data type size 
for which it is defined.*/

    int g = 4;
    int *ptr = &g;

    printf("ptr = %u\n", ptr); //4294957004

    /*when the increment/decrement operation is 
    used for pointers it will be incremented/decremented 
    by 4 bytes at once;*/

    --ptr;
    ++ptr;

    ptr += 3;
    ptr -= 4;
    ptr = ptr + 10;
    ptr = ptr - 9;

    /*Pointers can not be multiplied or divided by any value, only added or subtracted by someone! */

    printf("ptr = %u\n", ptr); //4294957008
    
    return 0;
}
