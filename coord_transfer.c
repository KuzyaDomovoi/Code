#include <stdio.h>
#include <math.h>

void coord_transfer(double degrees, int result[2], float result2[1]) {
    int dd = trunc(degrees);
    int mm = trunc((degrees - dd) * 60);
    float ss = ((degrees - dd) * 60 - mm) * 60;
    
    result[0] = dd;
    result[1] = mm;
    result2[0] = ss;
}

int main(void)
{
    double degrees;
    printf("dd.ddddd: ");
    if(scanf("%lf", &degrees) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    int result[2];
    float result2[1];
    coord_transfer(degrees, result, result2);

    printf("%d° %d' %.2f''\n", result[0], result[1], result2[0]);

    return 0;
}
