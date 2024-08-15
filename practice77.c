#include <stdio.h>
#include <errno.h>

int main(void)
{
    /*
    char str[] = "Function fputc with a-acces in action.\n";
    FILE* fw = fopen("/home/kuzya/Documents/k/file_1.txt", "a");
    if(fw == NULL) {
        printf("errno: %d\n", errno);
        perror("file_1.txt");
        return 1;
    }
    for(int i = 0; i < str[i]; ++i)
        fputc(str[i], fw);
    fclose(fw);
    */

    FILE* fr = fopen("/home/kuzya/Documents/k/file_1.txt", "r");
    if(fr == NULL) {
        printf("errno: %d\n", errno);
        perror("file_1.txt");
        return 1;
    }
    
    char buff[1000];
    char c;
    int i = 0;
    while((c = fgetc(fr)) != EOF)
        buff[i++] = c; 
    buff[i] = '\0';
    
    puts(buff);        
    
    fclose(fr);

    FILE* fr_1 = fopen("/home/kuzya/Documents/k/file_1.txt", "r");
    if(fr_1 == NULL) {
        printf("errno: %d\n", errno);
        perror("file_1.txt");
        return 1;
    }
    fseek(fr_1, 0, SEEK_END);
    int length = ftell(fr_1);

    for(int i = 1; i <= length; ++i) { 
        fseek(fr_1, -i, SEEK_END); 
        putchar(fgetc(fr_1)); 
    }
    
    putchar('\n');

    fclose(fr_1);

    return 0;
}
