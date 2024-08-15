#include <stdio.h>
 
enum {name_size = 10};
 
typedef struct
{
    char name[name_size]; // name od point;
    double x, y; // coordinats of point in 2d-space;
} POINT; // decl of a new var;
 
int main(void)
{
    POINT fig[] = { // array of points coordinats;
        {"Point 1", 0.0, 0.0}, // POINT struct var;
        {"Point 2", 4.23, -21.0},
        {"Point 3", 6.65, -31.34},
        {"Point 4", 3.2, -44.62},
        {"Point 5", -1.65, 1.0},
    };
 
    FILE* fp = fopen("my_file6.txt", "wb");
    if(fp == NULL) {
        perror("my_file6.txt");
        return 1;
    }
 
    int res = fwrite(fig, sizeof(POINT), sizeof(fig) / sizeof(*fig), fp); 
    /* 
       fig is an address of array; 
       sizeof(POINT) is a size of each POINT struct var; 
       sizeof(fig) / sizeof(*fig) is a number of POINTS in array; 
       fp is the stream to file for data write;
    */
    
    fclose(fp);
 
    printf("res = %d\n", res); // output a number of POINTs struct in the array;
 
    return 0;
}
