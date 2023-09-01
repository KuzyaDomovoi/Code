#include <stdio.h>

#define SIZE_BUFFEER 1024

int main(void)
{
/*Array is a fragment of memory that stores arbitary 
data using a variable.*/

    double f[30]; //30 * 8 = 240 bytes;
    char buffer [SIZE_BUFFEER];
    int marks[13];
    short ar[8 * 5];
    char bytes[sizeof(double)];

    //INCORRECT array declaration:
    //int n = 5;
    // int array[n];
    // float func[21.5];
    //int null_ar[0];

    return 0;
}
