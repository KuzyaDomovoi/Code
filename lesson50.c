#include <stdio.h>
#include <string.h> // to use the function strlen();
#include <stdlib.h> /* to use the functions: malloc() and free()
int atoi(), long atol(), long long atoll(), double atof();*/

int main(void)
{

// function for strings:

    double width = 2.4, height = 0.76, depth = 3.14;
    char name[] = "chair";
    const size_t size = strlen(name) + 100;
    char *info = malloc(size); // size (bytes) for var name; (malloc() and free())
    const char format[] = "(%s: %.2f x %.2f x %.2f)"; // %s is place for var name;

    sprintf(info, format, name, width, height, depth);
    puts(info);
    free(info); // memory is to make free;

    int var_i = -123; // var for integer numbers;
    double var_d = 35.7895; // var for double numbers;
    char str_var1[10]; // var 1 for chars;
    char str_var2[10]; // var 2 for chars;
    sprintf(str_var1, "%d", var_i); // transformation numbers (%d) to chars;
    sprintf(str_var2, "%.2f", var_d); // transformation numbers (%.2f) to chars;
    puts(str_var1); // -123 as a chars in string;
    puts(str_var2); // 35.7895 as a chars in string;

    int a = atoi("123"); // str for trans to int num and assign to var a;
    long b = atol("-234235346"); // str trans to long int num anr assign to var b;
    long long c = atoll("234235535456456"); // str trans to long long num and assign to var c;
    double d = atof("4564.4545"); // str trans to double num and assign to var d;

    printf("a = %d\nb = %ld\nc = %lld\nd = %f\n", a, b, c, d);

    return 0;
}
