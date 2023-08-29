#include <stdio.h>

int main(void)
{
    int I = 0, J = 0, K = 0, S;
    
    for(int i = -3; i <= 7; I += i, ++i)
        { }
        printf("I = %d\n", I);
        for(int j = 1; j <= 5; J += j, ++j)
            { }
            printf("J = %d\n", J);
            for(int k = 2; k <= 4; K += k, ++k)
                { }
                printf("K = %d\n", K);

    S = (I + J - K) * (I + J - K);
    printf("S = %d\n", S);

    return 0;
}
