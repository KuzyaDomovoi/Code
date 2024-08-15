#include <stdio.h>

int main(void)
{
    int r_var_i;
    double r_pi;
    char r_ch;

    FILE* fp = fopen("my_file5.txt", "rb");
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    fread(&r_var_i, sizeof(r_var_i), 1, fp); // &var_i is pointer to address of memory cell for var_i; sizeof(var_i) is a size of the var_i; 1 ia the number of data write in file fp; fp is a file to data write;
    fread(&r_pi, sizeof(r_pi), 1, fp);
    fread(&r_ch, sizeof(r_ch), 1, fp);

    fclose(fp);

    printf("r_var_i = %d, r_pi = %f, r_ch = %c\n", r_var_i, r_pi, r_ch);

    return 0;
}
