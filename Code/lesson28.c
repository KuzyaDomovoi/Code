#include <stdio.h>

int main(void)
{
    int arg = 7;
    int *ptr_arg, *ptr; //assigning of two variable to one data type 'int'; 

    ptr_arg = &arg;
    ptr = ptr_arg; // ptr = &arg;

    printf("* ptr_arg = %d, *ptr = %d, arg = %d\n", *ptr_arg, *ptr, arg);

    *ptr_arg = 100;

    printf("* ptr_arg = %d, *ptr = %d, arg = %d\n", *ptr_arg, *ptr, arg);

    return 0;
}
