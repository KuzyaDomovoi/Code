#include <stdio.h>
#include <string.h>

int main(void)
{
    
// String comparasion functions:

    char s1[12] = "Hello"; // string 1 for comparison;
    char s2[10] = "Hello"; // string 2 for comparison;

    const char *str1 = s1; // constable auxiliary pointer for operation with a string 's1';
    const char *str2 = s2; // condtable auxiliary pointer for operation with a string 's2';

    int i = 0; // auxiliary loop's counter;
    for(; str1[i] != '\0' && str2[i] != '\0'; ++i) // iterate the characters of strings (str1 and str2) until one of them will be != '\0';
        if(str1[i] != str2[i]) { // checking if a current char of str1 is not equal a current char of str2 (so will be checked is lengths of the two strings not equal);
            puts("Strings are not equal!");
        }
    if(str1[i] != str2[i]) { // checking if characters of current strings are not equal;
        puts("Srting length are not equal!");
    }
    puts("Strings are equal!");

    return 0;
}
