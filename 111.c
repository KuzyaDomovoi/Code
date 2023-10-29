#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int t = ((2 * 3.14 * 600 / 3.6) / (9.81 * tan(45 * 3.14 / 180))) * 180 / 360;

    printf("%d\n", t);

    return 0;
}
