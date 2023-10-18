#include <stdio.h>

// fflush() the func is used to cleaning the output stream only after data write operation;

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, -1};
    int length = sizeof(data) / sizeof(*data);
 
    FILE* fp = fopen("write_and_read.dat", "w");
    FILE* in = fopen("write_and_read.dat", "r");
    if(fp == NULL || in == NULL) {
        perror("write_and_read.dat");
        return 1;
    }
 
    for(int i = 0;i < length;++i)
        fprintf(fp, "%d ", data[i]);
 
    fflush(fp);
 
    int value;
    for(int i = 0; i < length; ++i)
        if(fscanf(in, "%d ", &value) == 1)
            printf("%d ",value);
 
    fclose(fp);
    fclose(in);
 
    return 0;
}
