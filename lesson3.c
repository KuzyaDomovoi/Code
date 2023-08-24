#include <stdio.h>

int main(void)
{
    long long var_lli = 0;

    int res = scanf("%lld", &var_lli);

    printf("res = %d: var_lli = %lld\n", res, var_lli);

    return 0;
}
