#include <stdio.h> 
#include <errno.h> 

int main(void)
{
    char str[] = "Function fputc() in action."; 

    FILE* in = fopen("my_file2.txt", "w"); 
    if(in == NULL) { 
        printf("errno: %d\n", errno);
        perror("my_file2.txt");
        return 1;
    }
    
    fseek(in, 0, SEEK_END); 
    int length = ftell(in); 

    for(int i = 0; str[i]; ++i) { 
        fseek(in, 0, SEEK_SET);
        fputc(str[i], in);
    }
    
    fclose(in); 
    
    return 0;
}
