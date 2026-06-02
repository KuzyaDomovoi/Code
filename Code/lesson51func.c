#include <stdio.h>

void print_hi(void)
{
    puts("Hello! I'm Sergey Balakirev!");
}

int main(void)
{

// Functions in C language:
/*DRY - Don't Repeat Yourself*/

// Declaration of functions
/*
data_type: void (if func has no data type), int, char, double, short (nouns);
func_name: get_coord, show_x, is_digit, ... (verbs)
param_set: ... if func has no one param: '(void)';
    
    <data_type><func_name>([param_set])
    {
        statement_1;
        ...
        statement_2;
    }
*/

    print_hi(); // func call operation;
    print_hi();

    return 0;
}
