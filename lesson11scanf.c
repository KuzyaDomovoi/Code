#include <stdio.h>

int main(void)
{
    int x;
    
    if(scanf("%d", &x) != 1) {
        printf("Error input\n");
        return 0;
    }
    
    if(x)x = -x;
    printf("x = %d\n", x);
    
    if(x >= 3 && x <= 11)
        printf("x in range[3; 11]\n");
    
    return 0;
}
