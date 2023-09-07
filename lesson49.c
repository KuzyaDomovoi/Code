#include <stdio.h>
#include <string.h> // to use the functions: strcmp() and strncmp();

int main(void)
{
    
// String comparasion functions:

    char s1[12] = "Hello"; // string 1 for comparison;
    char s2[10] = "Hello"; // string 2 for comparison;

    const char *str1 = s1; // constable auxiliary pointer for operation with a string 's1';
    const char *str2 = s2; // condtable auxiliary pointer for operation with a string 's2';

    int i = 0; // auxiliary loop's counter;
    for(; str1[i] != '\0' && str2[i] != '\0'; ++i) // iterate the characters of strings (str1 and str2) until one of them will be != '\0';
        if(str1[i] != str2[i]) { // checking if a current char of str1 is not equal a current char of str2;
            puts("Strings are not equal!");
            return 0;
        }
    if(str1[i] != str2[i]) { // checking current chars of two strings and they lengths are not equal;
        puts("Srting length are not equal!");
        return 0;
    }
    puts("Strings are equal!");

    if(strcmp(s1, s2) == 0) // if == 0 than strs are equal, if < 0 than s1 < s2 and if > 0 than s1 > s2;
        puts("Strings are equal!");
    else
        puts("Strings are not equal!");

    const char *strings[] = { // constable pointer's array;
        "Ship", "Shopping", "Shematic", "Super", "Car", "Sherif"
    };
    for(int i = 0; i < sizeof(strings) / sizeof(*strings); ++i)
        if(strncmp(strings[i], "Sh", 2) == 0)
            puts(strings[i]);

        return 0;
}
