#include <stdio.h>

int main(void)
{
// strings input/output to stdandard streams.
    
    char sp[] = "Hello, World";
    printf("%s, sp = %s\n", "Balakirev", sp);
    puts(sp); /* the function  added automatically a
    symbol '\n' at the end of sting.*/
    puts(sp);

    //char* gets(char* buf); // function 'gets' is not recomended to use!;
    
    char bf[10]; // 10 is length of array;

    scanf("%9s", bf); /* the function read strings up
    to whiterspace only (the first 9 chararcters), and
    inserts the last symbol '\0' (EOF) automatically (9+1).
    The value '9' is the maximum length to reading an
    array's data. But the using in practice the value of
    max read length in the function is not convenient and
    can be as a source of software vulnerability.*/
    
    fgets(bf, sizeof(bf), stdin); /*the function  is
    designed to read a string from arbitrary streams,
    usually from files and inserts the last symbol '\0'
    (EOF) automatically. Where: 
        'bf'         is an array's address;
        'sizeof(bf)' is a max length of bytes wich is
                     reading from input data stream.
        'stdin'      is a input data (file) stream.*/

// safe strings input:

    /* There are no standard full_fledged functions for
    reading strings in C language.*/

    /*int getchar(void) is a function that reads single
    characters from input data stream inside a loop 'while'.*/

    int max_len = sizeof(bf), i = 0; // var 'i' is a symbol counter of max len read;
    char *ptr = bf, ch; // variable 'ch' is used to reading a current character from input data stream;
    while((ch = getchar()) != '\n' && ch != EOF && i < max_len - 1)
        ptr[i++] = ch; // the pointer 'ptr' saves a current value;
    ptr[i] = '\0'; // at the end of string inserts EOF;
    puts(bf);

/*There are two new functions in C++ Language: scanf_s()
and gets_s() where can be pointed the max lenght of data
read.*/
    
    return 0;
}
