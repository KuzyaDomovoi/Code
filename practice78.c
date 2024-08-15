#include <stdio.h>

int main(void)
{
    char buff[1000];
    unsigned length = 0;

    FILE* fp = fopen("data_rubusd.csv", "r");
    if(fp == NULL) {
        perror("data_rubusd.csv");
        return 1;
    }
    while(fscanf(fp, "%c", &buff[length]) == 1) 
        length++;
    
    fclose(fp);
    
    for(int i = 0; i < length; ++i)
        printf("%c", buff[i]);
 
    return 0;
}
