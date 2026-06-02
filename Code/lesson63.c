#include <stdio.h>
#include <stdarg.h> // to use the pointers: 'va_list', 'va_start', 'va_arg', 'va_end';

/* Variadic funcs are the funcs with an arbitrary number
of stguments;*/

// int printf(const char *format, ...);
// int scanf(const char *format, ...);

int sum(int count, ...) // '...' means that an arbitrary numb of args can be passed here;
{
    int s = 0;
    va_list arg;
    va_start(arg, count); // should be passed a last param before '...', that is 'count';
    for(int i = 0; i < count; ++i) {
        s += va_arg(arg, int); // 'va_arg' returns a current variardic param and shift to a next variadic param from '...' as integer (int) datatype, which must be counted;
    }
    va_end(arg); // pointer to which will be passed params;
    return s;
}

int main(void)
{
    int res = sum(5, 1, 2, 3, 4, 5); // int count is 5 elements: 1, 2, 3, 4, 5;
    int res1 = sum(3, 1, 2, 3, 4, 5);
    printf("res = %d\n", res);
    printf("res1 = %d\n", res1);

    return 0;
}
