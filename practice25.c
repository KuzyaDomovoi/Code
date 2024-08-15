#include <stdio.h>

int main(void)
{
    int S = 0;
        for(int i = -3; i <= 7; ++i)
        for(int j = 1; j <= 5; ++j)
            for(int k = 2; k <= 4; ++k) {
                S += (i + j - k) * (i + j - k);
            }    
    printf("S = %d\n", S); //2750

    return 0;
}
