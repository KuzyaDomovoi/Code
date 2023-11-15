#include <stdio.h>
#include <math.h>

void coord_transfer(float grad, int result[3]) {
    int dd = trunc(grad);
    int mm = trunc((grad - dd) * 60);
    int ss = trunc(((grad - dd) * 60 - mm) * 60);
    
    result[0] = dd;
    result[1] = mm;
    result[2] = ss;
}

int main(void)
{
    float ddd;
    printf("dd.ddddd: ");
    if(scanf("%f", &ddd) != 1)
        printf("incorrect input!");
        return 0;

    int result[3];
    coord_transfer(ddd, result);

    printf("%d° %02d' %02d''\n", result[0], result[1], result[2]);

    return 0;
}
