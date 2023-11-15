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

    int lat_res[2];
    float lat_res2[1];
    int lng_res[2];
    float lng_res2[1];

    coord_transfer(lat_deg, lat_res, lat_res2);
    coord_transfer(lng_deg, lng_res, lng_res2);
  
    printf("lat  %02d° %02d' %.2f''\nlng %03d° %02d' %.2f''\n", 
            lat_res[0], lat_res[1], lat_res2[0], lng_res[0], lng_res[1], lng_res2[0]);

    return 0;
}
