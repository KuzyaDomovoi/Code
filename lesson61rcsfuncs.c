#include <stdio.h>

int rcs(int x)
{

// Recursive funcs is funcs which are called themselves, void rcs(int x);
//Recutsion depth;

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
