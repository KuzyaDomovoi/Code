#include <stdio.h>

int main(void)
{
    /*variable declaration*/
    int n, s;

    /*input data*/
    if(scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 0;
    }

    /*loop with 'for' procondition*/
    for(s = 0; n > 0; --n)
        s += n * n;

    /*data output*/
    printf("s = %d\n", s);

    return 0;
}
