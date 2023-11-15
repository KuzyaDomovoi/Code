#include <stdio.h>
#include <math.h>

void coord_transfer(double lat_deg, double lng_deg, int lat_res[2], float lat_res2[1], int lng_res[2], float lng_res2[1]) {
    int dd = trunc(lat_deg);
    int mm = trunc((lat_deg - dd) * 60);
    float ss = ((lat_deg - dd) * 60 - mm) * 60;
    
    int dd = trunc(lng_deg);
    int mm = trunc((lng_deg - dd) * 60);
    float ss = ((lng_deg - dd) * 60 - mm) * 60;    
    
    lat_res[0] = dd;
    lat_res[1] = mm;
    lat_res2[0] = ss;
   
    lng_res[0] = dd;
    lng_res[1] = mm;
    lng_res2[0] = ss;
}

int main(void)
{
    double lat_deg;
    double lng_deg;
    printf("lat dd.ddddd: ");
    if(scanf("%lf %lf", &lat_deg, &lng_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    printf("lng dd.ddddd: ");
    if(scanf("%lf %lf", &lat_deg, &lng_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    int res[2];
    float res2[1];
    coord_transfer(lat_deg, res, res2);

    printf("%d° %d' %.2f''\n", res[0], res[1], res2[0]);

    return 0;
}
