#include <stdio.h>

int rcs(int x)
{

// (void rcs(int x));
/* Recursive funcs are the funcs which are called themselves
and is used to iterate some hierarhical binary data or
directories and files which have complex structure or when
the use of loops is very difficult;
Recurcion is slower then loops!
Recursion depth is not endless and limited by steak
frame memory section. Therefore when the max rcs depth is
difficult to estimate it will be better to refuse it!*/

    printf("Down: x = %d\n", x);
    if(x > 1)
        rcs(x - 1);
    printf("Up: x = %d\n", x);
}

int main(void)
{
    rcs(4);

    return 0;
}
