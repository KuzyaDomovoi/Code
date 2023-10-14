#include <stdio.h>

char buf[128] = "Hello";

/*if the string is inserted out of any function (for 
example, above the function 'main') than it is locate
in a '.data' memory section promptly while a programm is
in load process.*/

int main(void)
{
    
// Data type 'string':

/* in C language is no data type 'string' therefor
an array of type 'char' is used here to store a sequence
of characters.
The  data type 'string' are stored in output executable
and than while a programm is in load proccess all these
strings are located in an immutable memory section
(in section .text usually). As a result when a prorramm is
completely loaded the each string literal has its own 
unique address which can be used by operations with the
corresponding string.

Syntax construction:

    char str[] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};
    char s[] = "Sergey Balakirev";
    char buffer[512] = "Hello, World";

    char b[] = "Hel" "lo"
    //            ", World";

    char sp[] = "Hello, \
World";*/

    char string[] = "a"; // is a string, not a character, because is used here double quotes;
    char sym = 'a'; // is a character, because is used here single quotes;

    const char* str = "Balakirev"; /* by using a pointer the characters in a string can be read only. 
    And it is recommended to use this with the keyword 'const'.*/
    char ss[] = "Balakirev"; // by using the array hier can be performed the all operations;

    //str[0] = 'A'; // exit with error code. An immutable memory section can not be changed;
    ss[0] = 'A'; // no error;

    char s[] = "I like programming in \"C\" language."; // characters escaping mechanism with symbol '\';
    puts(s); // I like programming in "C" language.

    char str_1[] = "\x61 \x4f";
    puts(str_1);

    return 0;
}
