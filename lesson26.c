#include <stdio.h>

int main(void)
{
    double x, s = 0.0;
    while(scanf("%lf", &x) == 1) {
        if(x < 0)
            break;
        s += x;
    }
    printf("s = %.2f\n", s);

    return 0;
}
