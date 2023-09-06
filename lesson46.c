#include <stdio.h>

int main(void)
{
    char sp[] = "Hello, World";
    printf("%s, sp = %s\n", "Balakirev", sp);
    puts(sp);
    puts(sp);

    //char* gets(char* buf); // function 'gets' is not recomended to use!;
    
    char bf[10]; // 10 is lenght of array;
    scanf("%9s", bf); // value '9' is the maximum lenght to reading array data and the last symbol must be '\0' (EOF), which is added automatically (9+1);
    puts(bf);

    return 0;
}
