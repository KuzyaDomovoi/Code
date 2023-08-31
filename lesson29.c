#include <stdio.h>

int main(void)
{
    int arg = 777; // 777 = 9 + 256^1 * 3;
    int *ptr_arg;
    char *ptr; // ! warning: assignment to 'char *' from incompatible type 'int *';
    void *p; // general type 'void *' is used to save adresses of variables, but it is not to use with memory cells (*p = 10; : error: invalid use of void expression);

    ptr_arg = &arg;
    ptr = (char *)ptr_arg; // assigning the variable 'ptr_arg' to compatible type 'char *'; 
    p = ptr;
    ptr_arg = p;

    *ptr = 1; // 1 + 256^1 * 3 = 769; the value '1' is writted to the first of four memory cells only and and changes the 'arg' value 777 to 769;
    
    printf("* ptr_arg = %d, *ptr = %d, arg = %d\n", *ptr_arg, *ptr, arg);
    
    return 0;
}
/* Pointers. Practice problems:
- the pointer refers to an unallocated memory area and some value is bieng written.
- when memory is in a program dynamically allocated (using the 'malloc'
function) and not freed (memory leak).*/
