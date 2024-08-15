#include <stdio.h>
#include <string.h> /* to use the functions: strcmp() and strncmp();
strchr(), strrchr(), strstr(), strpbrk()*/

int main(void)
{
    
// String comparasion:

    char s1[12] = "Hello"; // string 1 for comparison;
    char s2[10] = "Hello"; // string 2 for comparison;

    const char *str1 = s1; // constable auxiliary pointer for operation with a string 's1';
    const char *str2 = s2; // condtable auxiliary pointer for operation with a string 's2';

    int i = 0; // auxiliary loop's counter;
    for(; str1[i] != '\0' && str2[i] != '\0'; ++i) // iterate characters of strings (str1 and str2) until one of them will be != '\0';
        if(str1[i] != str2[i]) { // checking if a current char of str1 is not equal a current char of str2;
            puts("Strings are not equal!");
            return 0;
        }
    if(str1[i] != str2[i]) { // checking the current quantity (until == '\0') of chars of two strings to check they lengths are not equal;
        puts("Srting lengths are not equal!");
        return 0;
    }
    puts("Strings are equal!");

// String comparesion functions:

    if(strcmp(s1, s2) == 0) // if == 0 than strs are equal, if < 0 than s1 < s2 and if > 0 than s1 > s2;
        puts("Strings are equal!");
    else
        puts("Strings are not equal!");

    const char *strings[] = { // constable pointer's array ;
        "Ship", "Shopping", "Shematic", "Super", "Car", "Sherif"
    };
    for(int i = 0; i < sizeof(strings) / sizeof(*strings); ++i) // size calculation of each (i) string;
        if(strncmp(strings[i], "Sh", 2) == 0) // 2 chars for checking;
            puts(strings[i]);

    
    char str_0[] = "Abrakadabra";

    char *ptr_1 = strchr(str_0, 'a'); // the func 'strchr()' find the first char 'a' (*ptr = a) in the string 'str' from left to rigth;
    printf("str_0 = %p\nptr_1 = %p\n", str_0, ptr_1); // output of the addresses of strings: str and ptr;
    if(ptr_1 != NULL) // check if ptr is not '0';
        printf("*ptr_1 = %c\n", *ptr_1);

    char *ptr_2 = strrchr(str_0, 'a'); // the func 'strrchr()' find the first char 'a' (*ptr = a) in the string 'str' from rigth to left;
    printf("str_0 = %p\nptr_2 = %p\n", str_0, ptr_2);
    if(ptr_2 != NULL)
        printf("*ptr_2 = %c\n", *ptr_2); // output of the string;

    char *ptr = strstr(str_0, "ra"); // the func 'strstr()' find the fragment "ra....ra" (*ptr = ra (in double quotes) in the string 'str';
    printf("str_0 = %p\nptr = %p\n", str_0, ptr); // output of the addresses of strings: str and ptr;
    if(ptr != NULL)
        printf("ptr = %s\n", ptr); 

    char pass[] = "dfdfg90!#$$A";
    char *ptr_3 = strpbrk(pass, "@!#$^&?"); // the func 'strpbrk()' find any chars of @!#$^&? (*ptr = @!#$^&?) in the string 'str' from rigth to left;
    printf("pass = %p\nptr_3 = %p\n", pass, ptr_3); // output of the addresses of strings: str and ptr;
    if(ptr_3 != NULL) 
        printf("ptr_3 = %s\n", ptr_3);

    return 0;
}
