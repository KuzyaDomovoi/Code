#include <stdio.h>

// func fprintf() - performs a formatted write of data to the specified stream;

int main(void)
{
    const char* phones[][5] = { // 2d-array with undefined rows and 5 cols;
        {"+7", "917", "123", "45", "67"},
        {"+7", "904", "123", "45", "68"},
        {"+7", "906", "123", "45", "69"},
        {"+7", "962", "123", "45", "70"}
    };
    // +7(917)123-45-67;

    FILE* fp = fopen("my_file4.txt", "w");
    if(fp == NULL) {
        perror("my_file4.txt");
        return 1;
    }

    for(int i = 0; i < sizeof(phones) / sizeof(*phones); ++i)
        fprintf(fp,"%s(%s)%s-%s-%s\n", 
        phones[i][0], phones[i][1], phones[i][2], 
        phones[i][3], phones[i][4]);
 
    fclose(fp);
 
    return 0;
}
