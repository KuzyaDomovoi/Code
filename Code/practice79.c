#include <stdio.h>

enum{max_length = 10000};

int main(void)
{
    char data[max_length];
    char buffer[max_length];
    int length = 0;
 
    FILE* fp = fopen("/home/kuzya/Documents/k/google.csv", "r");
    if(fp == NULL) {
        perror("google.csv");
        return 1;
    }
 
    while(!feof(fp)) { 
        fgets(buffer, sizeof(buffer), fp);
 
        length = 0;
        while(fscanf(fp, "%s ", &data[length]) == 1)
            length++;
 
        puts(buffer);

        for(int i = 0; i < length; ++i)
            printf("%c", data[i]); 
        putchar('\n');
    }
 
    fclose(fp);

    return 0;
}
