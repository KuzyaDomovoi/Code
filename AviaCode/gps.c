#include <stdio.h>
#include <gps.h>    // for gps_*();
#include <errno.h>  // for error gps;
#include <stdlib.h> // for return EXIT_FAILURE;
#include <unistd.h> // for sleep time;
#include <math.h>   // for isfinite();

#define MODE_STR_NUM 4

static char *mode_str[MODE_STR_NUM] = {
    "n/a",
    "None",
    "2D",
    "3D"
};

int main()
{
    int rc;
    struct gps_data_t gps_data;
    struct timeval tv;

    if((rc = gps_open("localhost", "2947", &gps_data)) == -1) {
        printf("code: %d, reason: %s\n", rc, gps_errstr(rc));
        return EXIT_FAILURE;
    }

    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

    while(1) {
        if(gps_waiting(&gps_data, 2000000)) { // wait for 2 seconds to receive data
            printf("GPS status: %li Fix Mode: %i, Lat: %.6f Lng: %.6f \n", gps_data.set, gps_data.fix.mode, gps_data.fix.latitude, gps_data.fix.longitude);
            if((rc = gps_read(&gps_data, NULL, 0)) == -1) {
                printf("Error occured reading gps data. Code: %d, reason: %s\n", rc, gps_errstr(rc));
            } else { // Display data from the GPS receiver            
                if(MODE_SET != (MODE_SET & gps_data.set)) { // did not even get mode, nothing to see here
                    continue;
                }
            if(gps_data.fix.mode > 0 || MODE_STR_NUM <= gps_data.fix.mode) {
                gps_data.fix.mode = 0;
                printf("Fix mode: %s(%d) Time: ", mode_str[gps_data.fix.mode], gps_data.fix.mode);
            }
            if(TIME_SET == (TIME_SET & gps_data.set)) { // not 32 bit safe
                printf("%ld.%09ld ", gps_data.fix.time.tv_sec, gps_data.fix.time.tv_nsec);
            } else {
                puts("n/a\n");
            }
            if(isfinite(gps_data.fix.latitude) && isfinite(gps_data.fix.longitude)) {
                printf("Lat: %.6f Lng: %.6f\n", gps_data.fix.latitude, gps_data.fix.longitude); // Display data from the GPS receiver if valid.
            } else {
                puts("Lat: n/a Lng: n/a\n");
            }   
        }
        sleep(3);
        printf("out of sleep \n");
        /* When you are done... */
        gps_stream(&gps_data, WATCH_DISABLE, NULL);
        gps_close (&gps_data);
        }
    }

    return 0;
}
