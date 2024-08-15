#include <stdio.h>

// fflush() the func is used to cleaning the output stream only after data write operation;

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, -1}; // decl an array data;
    int length = sizeof(data) / sizeof(*data); // definition the size of the array data;
 
    FILE* fp = fopen("write_and_read.dat", "w"); // creating and opening new file 'write_and_read.dat' with write-acces;
    FILE* in = fopen("write_and_read.dat", "r"); // creating and opening the file with read-acces at the same time;
    if(fp == NULL || in == NULL) { // checking if 'pf' or 'in' is NULL or they are opened successfull;
        perror("write_and_read.dat"); // error output;
        return 1;
    }
 
    for(int i = 0; i < length; ++i) // iterate the array data;
        fprintf(fp, "%d ", data[i]); // write formatted data from array to the file 'fp';
 
    fflush(fp); // transfers data read to file 'fp' and cleans output stream after data write in file 'fp'; 
    //fclose(fp);

    int value; // decl a new temporary var for loop 'for' to data read from file 'in';
    for(int i = 0; i < length; ++i)
        if(fscanf(in, "%d ", &value) == 1) // conditions for data writting from file 'in' to the 'value';
            printf("%d ",value); // output data from 'value';
 
    fclose(fp);
    fclose(in);
 
    return 0;
}
