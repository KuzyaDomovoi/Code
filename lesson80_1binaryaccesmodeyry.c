#include <stdio.h>

// binary acess mode is to use for binary data reading/writting;
/*
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream); 
*/

int main(void)
{
    int var_i = -10; // 4 bytes;
    double pi = 3.141592653589793; // 8 bytes;
    char ch = 'S'; // 1 byte;
    
    // 4 + 8 + 1 = 13 bytes;

    FILE* fp = fopen("my_file5.txt", "wb");

    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    //fprintf(fp, "%d; %f; %c\n", var_i, pi, ch);
    fwrite(&var_i, sizeof(var_i), 1, fp); // &var_i is pointer to address of memory cell for var_i; sizeof(var_i) is a size of the var_i; 1 ia the number of data write in file fp; fp is a stream to file for data write;
    fwrite(&pi, sizeof(pi), 1, fp);
    fwrite(&ch, sizeof(ch), 1, fp);

    fclose(fp);

    return 0;
}
