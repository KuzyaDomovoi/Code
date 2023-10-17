#include <stdio.h>

int main(void)
{
    char google[5000]; 
    unsigned length = 0; 

    FILE* fp = fopen("/home/kuzya/Documents/k/google.csv", "r");
    if(fp == NULL) {
        perror("google.csv.csv");
        return 1;
    }

    while(fscanf(fp, "%c", &google[length]) == 1)
        length++;

    fclose(fp);

    for(int i = 0; i < length; ++i)
        puts(google);

    return 0;
}
