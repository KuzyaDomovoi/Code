#include <stdio.h>

int main(void)
{
    int arg = 777; // 777 = 9 + 256^1 * 3;
    int *ptr_arg;
    char *ptr; // ! warning: assignment to 'char *' from incompatible type 'int *';

    ptr_arg = &arg;
    ptr = ptr_arg;

    *ptr = 1; // 1 + 256^1 * 3 = 769; the value '1' is writted to the first of four memory cells only and and changes the 'arg' value 777 to 769;
    
    return 0;
}
