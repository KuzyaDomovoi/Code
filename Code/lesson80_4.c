#include <stdio.h>
 
enum {name_size = 10, max_points = 50}; // enumeration the sizes of name and number of elements in array for read data from a file;
 
typedef struct
{
    char name[name_size];
    double x, y;
} POINT; // decl a new struct var for array;
 
int main(void)
{
    POINT fig[max_points]; // array with a size 'max_points' where will be read data;
    int length = 0; // is an counter that stores a number of data read from a file;
 
    FILE* fp = fopen("my_file6.txt", "rb"); // open stream to file 'fp' with binary data read acces;
    if(fp == NULL) {
        perror("my_file6.txt");
        return 1;
    }
 
    while(fread(&fig[length], sizeof(POINT), 1, fp) == 1) // the loop while using func fread() reads the data from the stream to file 'fp';
    /* &fig[length] is an address in memory where to read current data from array; 
       sizeof(POINT) is a size of each POINT struct in the array; 
       1 is a piece of elements for reading from array; 
       fp is a stream to file 'fp' where to read data from; 
       == 1 it means a correct data reading;
    */ 
        length++;
 
    fclose(fp);
 
    for(int i = 0; i < length; ++i)
        printf("%s: (%.2f, %.2f)\n", fig[i].name, fig[i].x, fig[i].y);
 
    return 0;
}
