#include <stdio.h>
#include <errno.h> // to use func errno;

int main(void)
{
    char buff[100]; 

    FILE* in = fopen("my_file.txt", "r"); 
    if(in == NULL){ 
        puts("File open error"); 
        return 1;
    }
    
    char ch; 
    int i = 0; 
    while((ch = fgetc(in)) != EOF) 
        buff[i++] = ch;
    buff[i] = '\0';
    
    puts(buff);
    
    fclose(in); 
    
    return 0;
}
