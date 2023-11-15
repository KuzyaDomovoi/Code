#include <stdio.h>
#include <math.h>

void coord_transfer(double lat_deg, double lng_deg, int lat_res[2], float lat_res2[1], int lng_res[2], float lng_res2[1]) {
    int lat_dd = trunc(lat_deg);
    int lat_mm = trunc((lat_deg - lat_dd) * 60);
    float lat_ss = ((lat_deg - lat_dd) * 60 - lat_mm) * 60;
    
    int lng_dd = trunc(lng_deg);
    int lng_mm = trunc((lng_deg - lng_dd) * 60);
    float lng_ss = ((lng_deg - lng_dd) * 60 - lng_mm) * 60;    
    
    lat_res[0] = lat_dd;
    lat_res[1] = lat_mm;
    lat_res2[0] = lat_ss;
   
    lng_res[0] = lng_dd;
    lng_res[1] = lng_mm;
    lng_res2[0] = lng_ss;
}

int main(void)
{
    double lat_deg;
    double lng_deg;
    printf("lat dd.ddddd: ");
    if(scanf("%lf", &lat_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    printf("lng dd.ddddd: ");
    if(scanf("%lf", &lng_deg) != 1) {
        printf("incorrect input!\n");
        return 0;
    }
    int lat_res[2];
    float lat_res2[1];
    int lng_res[2];
    float lng_res2[1];   
    coord_transfer(lat_deg, lng_deg, lat_res, lat_res2, lng_res, lng_res2);

    printf("lat  %02d° %d' %.2f''\nlng %03d° %d' %.2f''\n", 
            lat_res[0], lat_res[1], lat_res2[0], lng_res[0], lng_res[1], lng_res2[0]);

    return 0;
}
