#include <stdio.h>

// Keyword 'extern':

extern int global_var; // the var is declared in the file 'modul.c'
/*'extern' is not a declaration but a description of var,
which later will be declared both in the current file or
in an another file (modul.c);*/

extern char global_str[]; // only description of global var;
extern int global_seed_randint;

int randint(int, int); /* only description of prototype func
and is an equivalent of keyword 'extern' for global vars;*/
//extern int randint(int, int); is equal int randint(int, int); 

char name[] = "Variables"; // located in .data RAM section;
double big_arg[10000000]; // located in .bss RAM section;

unsigned int counter()
{
    static unsigned int cnt = 10;
    return ++cnt; // 11;
}

int main(void)
{
    
// Keyword 'static':

/*it locates addresses of local vars in RAM .data or .bss 
section and allows the vars to take up large volumes of 
memory;*/

    int var_main; // automatic local var;
    static int var_st;

    static double big_arg[10000000]; /* exit with code = 0
    becouse before the local var's 'big-ar' datatype is
    passed the keyword 'static' and therefore it been
    located in RAM .bss section;*/

    printf("var_main = %d, var_st = %d\n", var_main, var_st);
    
    unsigned int times;
    times = counter();
    printf("times = %u\n", times); // 11;
    printf("counter(): %u\n", counter()); // 12;
    printf("counter(): %u\n", counter()); // 13;
    printf("counter(): %u\n", counter()); // 14;

    printf("global_var = %d\n", global_var); // 5;
    printf("global_str = %s\n", global_str); // Hello;
    
    int a = 1, b = 10; // definition of range(a, b) for prototype func 'int randint';
    printf("%d\n", randint(a, b)); // 4;
    printf("%d\n", randint(a, b)); // 7;
    printf("%d\n", randint(a, b)); // 8;

    printf("%d\n", global_seed_randint); // 0;

    return 0;
}
char global_str[100] = "Hello"; // definition the global var; 
