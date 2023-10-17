#include <stdio.h>

int main(void)
{
    char buff[30000] = {0};
    unsigned length = 0;

    FILE* fp = fopen("data_rubusd.csv", "r");
    if(fp == NULL) {
        perror("data_rubusd.csv");
        return 1;
    }
    while(fscanf(fp, "%c", &buff[length]) == 1) 
        length++;

    for(int i = 0; i < length; ++i)
        printf("%c", buff[i]);
 
    fclose(fp);
 
    return 0;
}
