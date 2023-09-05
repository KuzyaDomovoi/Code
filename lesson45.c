#include <stdio.h>

char buf[128] = "Hello";

/*if the string is inserted out of any function (for 
example, above the function 'main') than it is locate
in a '.data' memory section promptly while a programm is
in load process.*/

int main(void)
{
// Strings:

/* in C language is no data of type 'string' therefor
an array of type 'char' is used here to store a sequence
of characters.
The string data are stored in output executable and than
while a programm is in load proccess all these strings
are located in an immutable memory section
(in section .text usually). As a result when a prorramm is
completely loaded the each string literal has its own 
unique address which can be used by operation with the
corresponding string.*/

    char str[] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};
    char s[] = "Sergey Balakirev";
    char buffer[512] = "Hello, World";

    char b[] = "Hel" "lo"
                ", World";

    char sp[] = "Hello, \
World";

    char string[] = "a"; // is a string, not a symbol, becouse is used here double quotes;
    char sym = 'a'; // is a symbol only, because - single quotes;

    return 0;
}
