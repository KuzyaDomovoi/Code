#include <stdio.h>
#include <gps.h>
#include <math.h>

#define MODE_STR_NUM 4

static char *mode_str[MODE_STR_NUM] = {
    "n/a",
    "None",
    "2D",
    "3D"
};

int main(int argc, char *argv[])
{
    struct gps_data_t gps_data;

    if(gps_open("localhost", "2947", &gps_data) == -1) {
        printf("GPS open error\n");
        return 1;
    }


    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

    while (gps_waiting(&gps_data, 5000)) {
        if (gps_read(&gps_data, NULL, 0) == -1) {
            printf("GPS read error\n");
            return 2;
        }
        if (MODE_SET != (MODE_SET & gps_data.set)) { // did not even get mode, nothing to see here
            continue;
        }
        if (gps_data.fix.mode < 0 || MODE_STR_NUM <= gps_data.fix.mode) {
            gps_data.fix.mode = 0;
        }
        printf("Fix mode: %s (%d) Time: ", mode_str[gps_data.fix.mode], gps_data.fix.mode);
        if ((TIME_SET & gps_data.set) == TIME_SET) { // not 32 bit safe
            printf("%ld.%09ld ", gps_data.fix.time.tv_sec, gps_data.fix.time.tv_nsec);
        } else {
            puts("n/a ");
        }
        if (isfinite(gps_data.fix.latitude) && isfinite(gps_data.fix.longitude)) { // Display data from the GPS receiver if valid.
            printf("Lat %.6f, Lon %.6f\n", gps_data.fix.latitude, gps_data.fix.longitude);
        } else {
            printf("Lat n/a, Lon n/a\n");
        }
    }
    // When you are done...
    gps_stream(&gps_data, WATCH_DISABLE, NULL);
    gps_close(&gps_data);

    return 0;
}
