#include <stdio.h>

void swap_2(int *a, int *b)
{
    int t = *a; // assigning a value from memory cell of pointer's address '*a' to temp var 't';
    *a = *b; // than assigning a value from memory sell of pointer's address '*b' to memory cell of pointer's address '*a' as new value;
    *b = t; // and value of temp var 't' is assigned to memory cell of pointer's address '*b' as a new value;
}
int main(void)
{

// Pointers as parameters in funcs:

    //short var_a = 10; // var_a has value '10' initially;
    //short *ptr = &var_a; // than it is assigning a cell's memory address to var_a via pointer *ptr;
    //*ptr = 5; // using pointer *ptr is assigning a new value '5' to cell's memory address of the var_a;

    int x = 5, y = 10;
    swap_2(&x, &y); // assigning addresses (&) to var x and y via pointers (*a snd *b from func swap_2 to func main);
    printf("x = %d, y = %d\n", x, y); // x = 10, y = 5;

    return 0;
}
