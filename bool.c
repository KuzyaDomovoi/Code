#include <stdio.h>

int main(void)
{
    int a;
    int x = -90;
    int y = 90;

    if(scanf("%d", &a) != 1) {
        printf("Error input\n");
        return 0;
    }
   
    if(a < x || a > y)
        printf("x is not in range!\n");
        return 0;

    return 0;
}
