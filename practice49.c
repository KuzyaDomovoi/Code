#include <stdio.h>

int main(void)
{
    char s1[12] = "Hello";
    char s2[10] = "Hello";

    const char *str1 = s1;
    const char *str2 = s2;

    int i = 0;
    for(; str1[i] != '\0' || str2[i] != '\0'; ++i) {
        if(str1[i] != str2[i]) {
            puts("Strings are not equal!");
            return 0;
        }
    }
    puts("Strings are equal!");

    return 0;
}
