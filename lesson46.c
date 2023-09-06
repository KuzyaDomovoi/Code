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
    
    char bf[10]; // 10 is lenght of array;

    scanf("%9s", bf); /* the function read strings up
    to whiterspace only (the first 9 chararcters), and
    inserts the last symbol '\0' (EOF) automatically (9+1).
    The value '9' is the maximum lenght to reading an
    array's data. But the using in practice the value of
    max read lenght in the function is not convenient and
    can be as a source of software vulnerability.*/
    
    fgets(bf, sizeof(bf), stdin); /**/

//safe strings input:

    int max_len = sizeof(bf), i = 0; // var 'i' is a symbol counter of max len read;
    char *ptr = bf, ch; // variable 'ch' is used to reading a current character from input data stream;

    while((ch = getchar()) != '\n' && ch != EOF && i < max_len - 1)
        ptr[i++] = ch; // 

    ptr[i] = '\0';

    puts(bf);

    return 0;
}
