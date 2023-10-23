#include <stdio.h>

int main(void)
{
    //int n;
    //int s = 0;

    //if(scanf("%d", &n) != 1) {
    //    printf("Incorrect input");
    //    return 0;
    //}

    //while(n > 0) {
    //    s += n * n;
    //    n--;
    //}

    

    //int i = 0;
    //while (++i <= n && i <= 10)
    //  s += i * i;

    int s = 0;
    int x;

    //while(scanf("%d", &x) == 1 && x != 0)
    //    s += x;

    while(scanf("%d", &x) == 1 && x != 0) {
        int res = x % 2;
        if(res % 2 == 0)
            s += x;
    }
    printf("s = %d\n", s);

    return 0;
}
