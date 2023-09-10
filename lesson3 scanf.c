#include <stdio.h>

int main(void)
{
    long long var_lli = 0;
    double var_d = 0; // three decimal places;
    float var_f = 0; // two decimal places;

    int res = scanf("%lld %lf %f", &var_lli, &var_d, &var_f);

    printf("res = %d: var_lli = %lld, vad_d = %.3lf, var_f = %.2f\n", res, var_lli, var_d, var_f);

    return 0;
}
