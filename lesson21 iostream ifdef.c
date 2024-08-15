#include "tmp/printf.h"
#define LANG_C

#if defined(LANG_C) //#ifdef LANG_C
#   include <stdio.h>
#else
#   include<iostream>
#endif

int main(void)
{
    int x = 5;
#ifdef LANG_C
    printf("%d\n", x);
#else
    std::cout << x << std::endl;
#endif

    printf("Hello, world!\n"); //Hello, world!
    return 0;
}
