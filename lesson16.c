#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int range = 10;
    int r_1 = rand() % range; // [0; range];
    int r_2 = rand() % range - 5; // [-5; range - 5];
    int r_3 = rand() + rand();

    double range_float = (double)rand() / (double)RAND_MAX; // [0; 1];

    printf("%d, %d, %d, %.2f\n", r_1, r_2, r_3, range_float);

    return 0;
}
