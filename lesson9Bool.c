#include <stdio.h>
#include <stdbool.h> // to use the statement bool;

int main(void)
{
    //bool fl_view = 10; // if fl_view = 0 is false, if != 0 is true;

    double x = 5.67;
    bool fl_view = x < 10;
    bool fl_view1 = x > 6;

    printf("Size of bool = %ld, fl_view = %d, fl_view1 = %d\n", sizeof(bool), fl_view, fl_view1);
    printf("%d, %d\n", fl_view, fl_view1); // 1;

    return 0;
}
