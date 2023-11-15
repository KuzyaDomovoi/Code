#include <stdio.h>
#include <math.h>

void coord_transfer(float degrees, int result[3]) {
    int dd = trunc(degrees);
    int mm = trunc((degrees - dd) * 60);
    int ss = trunc(((degrees - dd) * 60 - mm) * 60);
    
    result[0] = dd;
    result[1] = mm;
    result[2] = ss;
}

int main(void)
{
    float degrees;
    printf("dd.ddddd: ");
    if(scanf("%f", &degrees) != 1)
        printf("incorrect input!\n");
        return 0;

    //int result[3];
    //coord_transfer(degrees, result);

    int dd = trunc(degrees);
    int mm = trunc((degrees - dd) * 60);
    int ss = trunc(((degrees - dd) * 60 - mm) * 60);

    printf("%d° %d' %d''\n", dd, mm, ss);
    printf("%d°\n", dd);

    //printf("%d° %d' %d''\n", result[0], result[1], result[2]);

    return 0;
}
