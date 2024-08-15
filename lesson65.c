#include <stdio.h>

int main(void)
{
    int a = 1, b = 3;
    int t = a + b; // the var 't' is located outside the lower block (in another memory section);
    if(a < b) 
    {
        int t = a; // if-condition with declared var 'int t' is perfomed inside the block only and it exist only in this block;
        a = b;
        b = t;
    }

    printf("a = %d, b = %d, t = %d\n", a, b, t);

    {
        t = a; // if-condition with undeclared var 't' is perfomed inside the block only but it exist also outside the block;
        a = b;
        b = t;
    }

    printf("a = %d, b = %d, t = %d\n", a, b, t);

    return 0;
}
