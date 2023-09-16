#include <stdio.h>

// Keyword static:
/*it locates addresses of vars in RAM .data or .bss section
and allows the vars to take up large volumes of memory;*/

char name[] = "Variables"; // located in .data RAM section;
double big_arg[10000000]; // located in .bss RAM section;

unsigned int counter()
{
    static unsigned int cnt = 10;
    return ++cnt; // 11;
}

int main(void)
{
    int var_main; // automatic local var;
    static int var_st;

    static double big_arg[10000000]; // exit with code = 0 becouse before the local var's 'big-ar' datatype is assigned the keyword 'static' and therefore it been located in RAM .bss section;

    printf("var_main = %d, var_st = %d\n", var_main, var_st);
    
    unsigned int times;
    times = counter();
    printf("times = %u\n", times); // 11;
    printf("counter(): %u\n", counter()); // 12;
    printf("counter(): %u\n", counter()); // 13;
    printf("counter(): %u\n", counter()); // 14; 
    
    return 0;
}