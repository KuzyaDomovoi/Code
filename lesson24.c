#include <stdio.h>

int main(void)
{
    //5! = 1 * 2 * 3 * 4 * 5;   0! = 1; 

    int n = 5, p = 1;

    for(int i = 1; i <= n; ++i)
        p = p * i;

    printf("p = %d\n", p);

    int x, y = 1;
    if(scanf("%d", &x) != 1 || x < 0) {
        printf("Incorrect input\n");
        return 0;
    }
    for(y; x > 0; --x)
        y *= x;
    
    printf("y = %d\n", y);

    return 0;
}
