#include <stdio.h>

int main(void)
{
// Strings:

/* in C language is no data of type 'string' therefor
an array of type 'char' is used here to store a sequence
of characters.*/

    char str[] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};
    char s[] = "Sergey Balakirev";
    char buffer[512] = "Hello, World";

    char b[] = "Hel" "lo"
                ", World";

    char sp[] = "Hello, \
World";

    char string[] = "a"; // is a string, no a symbol, becouse is used here double quotes;
    char sym = 'a'; // is a symbol, because - single quotes;

    return 0;
}
