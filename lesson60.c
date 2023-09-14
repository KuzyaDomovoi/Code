#include <stdio.h>

double big_ar[10000000]; // exit code 0 because the array 'big_ar' is located outside the func main that is, in main memory section;

int main(void)
{

//funcs calling. Steak frame (has a size of some megabytes):
// "Steack Overlow"
// funcs: malloc() and free() are used to locating dynamically created data in main memory section when func is called, ; 
    int var;
    printf("var = %d\n", var);

    //double big_ar[10000000]; // Segmentation fault (core dumped), exit code != 0 becaude the array is located in steak frame memory section;

    return 0;
}
