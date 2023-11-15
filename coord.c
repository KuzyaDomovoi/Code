#include <stdio.h>
#include <math.h>

void coord_transfer(double deg, int res[2], float res2[1]) {
    int dd = trunc(deg);
    int mm = trunc((deg - dd) * 60);
    float ss = ((deg - dd) * 60 - mm) * 60;
    
    res[0] = dd;
    res[1] = mm;
    res2[0] = ss;
}

int main(void)
{
    double lat_deg;
    double lng_deg;
    printf("lat in degrees: ");
    if(scanf("%lf", &lat_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    printf("lng in degrees: ");
    if(scanf("%lf", &lng_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }

    int res[2];
    float res2[1];
  
    coord_transfer(lat_deg, res, res2);
    coord_transfer(lng_deg, res, res2);

    printf("lat  %02d° %02d' %.2f''\nlng %03d° %02d' %.2f''\n", 
            res[0], res[1], res2[0], res[0], res[1], res2[0]);

    return 0;
}
