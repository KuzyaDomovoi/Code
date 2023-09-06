#include <stdio.h>
#include <string.h> // to use the func strcpy() and strcpy();

int main(void)
{

// Copy strings;

    char source[100] = "Source string"; // array with string data;
    char destination[10]; // is array to copy the characters;

    const char *src = source; // constable auxiliary pointer *src referring to the array 'source';
    char *dst = destination; // auxiliary pointer *dst referring to the array 'destination';
    int max_len_copy = sizeof(destination); // the variable 'max_len_copy' contains a max length of characters for the array 'destination';
    while(*src != '\0' && max_len_copy-- > 1)
        *dst++ = *src++; // char-by-char copying from array 'source' to array 'destination';
    *dst = '\0'; // character '\0' as EOF insert is requared, because when the pointer '*src' is not '0' the loop 'while' will be interrupted;
    puts(destination);

// Copy strings functions:

    char source_1[100] = "Source string";
    char destination_1[10];

    strcpy(destination_1, source_1);
    puts(destination_1);
    
    int max_len = sizeof(destination_1) - 1; // var for specify the max array size;
    strncpy(destination_1, source_1, max_len); // char copy to array 'destination_1' from array 'source_1' by max size of array 'destination_1';
    strncpy(destination_1, "Hello World", max_len);
    destination_1[max_len] = '\0'; // inserting the EOF;
    puts(destination_1);

    return 0;
}
