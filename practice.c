#include <stdio.h>

enum {str_size = 70, max_rows = 30};

typedef struct
{
    char string[str_size];
} ROW;

int main(void)
{
    ROW w_string[] = { 
        {"Srting 1 0.0, 0.0"}, 
        {"Srting 2 4.23, -21.0"},
        {"Srting 3 6.65, -31.34"},
        {"Srting 4 3.2, -44.62"},
        {"Srting 5 -1.65, 1.0"},
    };

    FILE* fp = fopen("/home/kuzya/Documents/k/2023.xlsx", "wb");
    if(fp == NULL) {
        perror("2023.xlsx");
        return 1;
    }

    int res = fwrite(w_string, sizeof(ROW), sizeof(w_string) / sizeof(*w_string), fp);

    fclose(fp);

    printf("res = %d\n", res);
    
    ROW r_string[max_rows];
    int length = 0; 
 
    FILE* fr = fopen("/home/kuzya/Documents/k/2023.xlsx", "rb"); 
    if(fr == NULL) {
        perror("2023.xlsx");
        return 1;
    }
 
    while(fread(&r_string[length], sizeof(ROW), 1, fr) == 1) 
        length++;
 
    fclose(fr);
 
    for(int i = 0; i < length; ++i)
        printf("%s\n", r_string[i].string);
 
    return 0;
}
