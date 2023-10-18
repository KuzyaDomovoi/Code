#include <stdio.h>

enum{max_length = 5000};

int main(void)
{
    double data[max_length];
    char buffer[max_length];
    int length = 0;
 
    FILE* fp = fopen("data_rubusd_2.csv", "r");
    if(fp == NULL) {
        perror("data_rubusd_2.csv");
        return 1;
    }
 
    while(!feof(fp)) { 
        fgets(buffer, sizeof(buffer), fp);
 
        length = 0;
        while(fscanf(fp, "%lf; ", &data[length]) == 1)
            length++;
 
        puts(buffer); 

        for(int i = 0; i < length; ++i)
            printf("%.2f ", data[i]); 
        putchar('\n');
    }
 
    fclose(fp);

    return 0;
}
