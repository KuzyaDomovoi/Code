#include <stdio.h>

// Local and global variables:

// external code block;
/* In the external code block the vars and their values
are created in the Random Acces Memory (RAM) (in the
section .bss when they have not initial values or in
the section .data when they have initialy values) and are
limited by the device's RAM only;
The vars appear in the device's RAM when the program
starts and remain in the memory unchangeble while the 
program is running;
Their scope is global and they can be used anywhere in
the program, that is the vars are global.
They are static vars, that is the vars have their addresses as const*/

char name[] = "Variables";
double big_ar[10000000]; // exit code = 0;
//int global_var_1 = 5;
const int global_var_1 = 5;
int global_var_2 = 5 * 7;
int global_var_3 = sizeof(name) + 1;
//int global_var_4 = global_var_1; // if global_var_1 is not assigned as 'const' than exit with code != 0;
int global_var_4 = global_var_1; // no error only when global_var_1 is assigned as 'const';

int main(void)
{
// internal code block;
// All vars with a limited scope are called the local vars;

    int var_main; // the vars should be in enternal code block as auxiliary not as database!;

    //double big_ar[10000000]; // exit with code !=0 because the array has a big var and it is not passed in steak frame memory section;

/* In the internal code block the vars and their values
are created in the steak frame memory section during the
program is in opetate and so their initial values can
be defined by any expressions allowed in the C-language;
When the func is completed the vars and their values 
disappear from the steak frame;
They are automatical and have scope within a func.*/

    int a = 1;
    int b = a * 2 + global_var_2;
    int size = global_var_3 * 10;

    printf("var_main = %d\n", var_main);

/* Hier can be used both local and global vars with help
of funcs malloc() and free();
But it is better not to use regular vars for big data!;*/

    return 0;
}
