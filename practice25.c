#include <stdio.h>

int main(void)
{
    int i_max = 7;
    int j_max = 5;
    int k_max = 4;
    int S;
    
    for(int i = -3; i <= i_max; ++i)
        for(int j = 1; j <= j_max; ++j)
            for(int k = 2; k <= k_max; ++k) {
                S += (i + j - k) * (i + j - k);
            }    
    printf("S = %d\n", S); //2750

    return 0;
}
