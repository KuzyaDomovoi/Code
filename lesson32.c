#include <stdio.h>

int main(void)
{
    int g = 476789; //476789 = 117 + 256^1 * 70 + 256^2 * 7;
    char *ptr = (char *)&g; /*if type 'char' - reading the
    first memory cell only from the variable's address.*/

    for(int i = 0; i < sizeof(int); ++i) /* iterate over
    all memory cells from the variable's address.*/
        printf("%d ", *ptr++); // the postfix form '*(ptr++)' unary operations preority;
        //ptr++; 
        /*If the prefix form '*++ptr', than increment 
        operation is perfomed first and than the 
        declaration of pointer.*/

   return 0;
}
