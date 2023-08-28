#include <stdio.h>

#define SQ_PR(A, B) ((A) * (B))

int main(void)
{
    int x = 3, y = 8;
    int res = SQ_PR(x + 2, y - 3); //((x + 2) * (y - 3));
    printf("res = %d\n", res);

    return 0;
}
