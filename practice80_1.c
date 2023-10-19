#include <stdio.h>

enum {name_size = 50, max_rows = 350};

typedef struct
{
    char name[name_size];
    int x;
} ROW;

int main(void)
{
    ROW contact[max_rows];
    int length = 0; 
 
    FILE* fr = fopen("/home/kuzya/Documents/k/google.csv", "rb"); 
    if(fr == NULL) {
        perror("google.csv");
        return 1;
    }
 
    while(fread(&contact[length], sizeof(ROW), 1, fr) == 1) 
        length++;
 
    fclose(fr);
 
    for(int i = 0; i < length; ++i)
        printf("%s: %d\n", contact[i].name, contact[i].x);
 
    return 0;
}
