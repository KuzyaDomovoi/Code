#include <stdio.h>
#include <gps.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

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
        if (gps_waiting (&gps_data, 5000000)) { // wait for 5 seconds to receive data
        printf("GPS set_status: %li GPS Fix Mode: %i, GPS Lat: %.6f GPS Lng: %.6f \n", gps_data.set, gps_data.fix.mode, gps_data.fix.latitude, gps_data.fix.longitude);
        if((rc = gps_read(&gps_data, NULL, 0)) == -1) {
            printf("error occured reading gps data. code: %d, reason: %s\n", rc, gps_errstr(rc));
        } else { // Display data from the GPS receiver            
            if(MODE_SET != (MODE_SET & gps_data.set)) { // did not even get mode, nothing to see here
            continue;
            }
            if (0 > gps_data.fix.mode ||
                MODE_STR_NUM <= gps_data.fix.mode) {
                gps_data.fix.mode = 0;
            }
            printf("Fix mode: %s (%d) Time: ", mode_str[gps_data.fix.mode], gps_data.fix.mode);
            if(TIME_SET == (TIME_SET & gps_data.set)) { // not 32 bit safe
                printf("%ld.%09ld ", gps_data.fix.time.tv_sec, gps_data.fix.time.tv_nsec);
            } else {
                puts("n/a ");
            }
            if(isfinite(gps_data.fix.latitude) && isfinite(gps_data.fix.longitude)) {
                printf("Lat %.6f Lon %.6f\n", gps_data.fix.latitude, gps_data.fix.longitude); // Display data from the GPS receiver if valid.
            } else {
                printf("Lat n/a Lon n/a\n");
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
