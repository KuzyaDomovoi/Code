#include <stdio.h>

int main(void)
{
    long long var_lli = 0;
    double var_d = 0;
    float var_e = 0;

    int res = scanf("%lld %lf %f", &var_lli, &var_d, &var_e);

    printf("res = %d: var_lli = %lld, vad_d = %.3lf, var_e = %.2f\n", res, var_lli, var_d, var_e);

    return 0;
}
