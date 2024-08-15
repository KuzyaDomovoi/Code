#include <stdio.h>
#include <string.h> // to use the functions: strcat() and strncat();

int main(void)
{
    //char str[100] = "Length of the string";

    //const char *buf = str; // *buf reads the current char from string;
    //size_t length = 0; // 
    //while(*buf++) // while code reading != '\0' than loop is continued until the loop meets '\0' (EOF) and so the length of string will be counted;
    //length++; // var is incremented;

// strlen() function:

    //size_t length = strlen(str);

    //printf("length = %zu\n", length);

// strcat() and strncat() functions:

    char str_cat[100] = "Sergey";
    char str[15] = "Balakirev"; // free size position in array 'str' is [15] - 9 (Balakirev) = 6;

    strcat(str_cat, str); // copy to array 'str_cat';
    printf("%s", str_cat);

    printf("\n");

    size_t max_add = sizeof(str) - strlen(str) - 1; // define max free size position in array 'str' and '- 1' is a place for '\0' (EOF) /= 6 - 1;
    strncat(str, str_cat, max_add); // copy to array 'str' by max size position of free size in array 'str';
    str[sizeof(str) - 1] = '\0'; // add EOF;

    printf("%s", str);

    return 0;
}
