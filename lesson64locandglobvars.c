#include <stdio.h>

// Local and global variables:

// external code block;
char name[] = "Variables";
/* In the external code block the vars and their values
are created in main memory section and when all funcs
are completed they (vars and their vals) remain in the
main memory;*/

// All vars with a limited scope are called the local vars;

int main(void)
{
// internal code block;
    int var_main;
/* in the internal code block the vars and their values
are created in steak frame memory section and when a func
is completed they (vars and their vals) disappear from the
steak frame;
They are automatical and have scope within a func;*/

    printf("var_main = %d\n", var_main);

    return 0;
}