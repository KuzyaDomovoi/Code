#include <stdio.h>
#include <gps.h>    // for gps_*();
#include <errno.h>  // for error gps;
#include <stdlib.h> // for return EXIT_FAILURE;
#include <unistd.h> // for sleep time;
#include <math.h>   // for isfinite();
#include <time.h>

#define STATUS_FIX 4

static char *mode_str[STATUS_FIX] = {
    "n/a",
    "None",
    "2D",
    "3D"
};
int rc;
struct gps_data_t gpsData;

int main(void) {
    if((rc = gps_open ("localhost", "2947", &gpsData)) == -1) {
        printf("code: %d, reason: %s\n", rc, gps_errstr(rc));
        return EXIT_FAILURE;
    }

    gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL); // Ждем пару секунд пока будут приняты данные GPS
    if(gps_waiting (&gpsData, 2000000)) { // Читаем данные с GPS приемника
        if((rc = gps_read(&gpsData, NULL, 0)) == -1) {
            printf("code: %d, reason: %s\n", rc, gps_errstr(rc));
        } else { // Показать данные GPS приемника
            if((gpsData.set == STATUS_FIX) && (gpsData.fix.mode == MODE_2D || gpsData.fix.mode == MODE_3D) &&
                !isnan(gpsData.fix.latitude) && 
                !isnan(gpsData.fix.longitude)) {
                printf ("[INFO] Latitude: %.6f Longitude: %.6f\n", gpsData.fix.latitude, gpsData.fix.longitude);
            }
        }
    }
    while(1) {}

    return 0;
}