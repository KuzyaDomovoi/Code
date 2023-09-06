#include <stdio.h>

int main(void)
{
// strings input/output to stdandard streams.

    
    char sp[] = "Hello, World";
    printf("%s, sp = %s\n", "Balakirev", sp);
    puts(sp);
    puts(sp);

    //char* gets(char* buf); // function 'gets' is not recomended to use!;
    
    char bf[10]; // 10 is lenght of array;
    /*scanf("%9s", bf); /* value '9' is the maximum lenght
    to reading array data and plus the last symbol must
    be '\0' (EOF), which is added automatically (9+1);
    But the using in practice the value of max read lenght
    in the function 'scanf' is not convenient.*/
    //fgets(bf, sizeof(bf), stdin);

//safe strings input:

    int max_len = sizeof(bf), i = 0; // var I is a counter;
    char *ptr = bf, ch; // variable 'ch' is used to reading a current character from input data stream;

    while((ch = getchar()) != '\n' && ch != EOF && i < max_len - 1)
        ptr[i++] = ch;

    ptr[i] = '\0';

    puts(bf);

    return 0;
}
