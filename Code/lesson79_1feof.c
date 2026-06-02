#include <stdio.h>

// feof() the func returns '1' when EOF is reached or returns '0' if EOF is not reached;

enum{max_length = 1000};

int main(void)
{
    double data[max_length]; // array for reading a num-data in stream 'fp'
    char buffer[max_length]; // arrray for reading a char-data in stream 'fp';
    int length = 0; // the var stores a number of data read;
 
    FILE* fp = fopen("data_rubusd_2.csv", "r");
    if(fp == NULL) {
        perror("data_rubusd_2.csv");
        return 1;
    }
 
    while(!feof(fp)) { // the loop while is in action until EOF is not reached, that is the func 'feof' returns '1' when EOF is reached or returns '0' - if not EOF;
        fgets(buffer, sizeof(buffer), fp); // reads current string (current head) from buffer;
 
        length = 0; // counter of data read for loop while;
        while(fscanf(fp, "%lf; ", &data[length]) == 1) // the loop while using func 'fscanf' reads (if loop returns 1) the array 'double data[max_length]' with specifeid formatted data (%lf) until (when loop returns 0) EOF in the current string is reached;
            length++;
 
        puts(buffer); // output current char-data from buffer;

        for(int i = 0; i < length; ++i)
            printf("%.2f ", data[i]); // output num-data from data;
        putchar('\n'); // transfers to next string, that is to loop while(!feof(fp)) when it returns 1 (end of file);
    }
 
    fclose(fp);

    return 0;
}
