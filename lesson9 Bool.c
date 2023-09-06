#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    //bool fl_view = 10; // if fl_view = 0 is false, if != 0 is true;

    double x = 5.67;
    bool fl_view = x < 10; //0

    //printf("Size of bool = %ld, fl_view = %d\n", sizeof(bool), fl_view);
    printf("%d\n", fl_view);

    return 0;
}
