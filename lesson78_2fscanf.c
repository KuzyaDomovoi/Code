#include <stdio.h>

// func fprintf() - performs a formatted read of data from the specified stream;

enum {max_length = 1024}; // decl of constanta 'max_length' that is the size of an array;

int main(void)
{
    double rub_usd[max_length] = {0.0}; // the array with the size 'max_length';
    unsigned length = 0; // var 'length' stores the number of files read;

    FILE* fp = fopen("data_rubusd.csv", "r"); // open the file "data_rubusd.cvs" for reading;
    if(fp == NULL) {
        perror("ata_rubusd.csv");
        return 1;
    }

    while(fscanf(fp, "%lf; ", &rub_usd[length]) == 1) // performs a formatted read of data from the specified stream while the func fscanf returns == 1(while data read is correct);
        length++;

    fclose(fp);

    for(int i = 0; i < length; ++i)
        printf("%.2f; ", rub_usd[i]);

    return 0;
}
