#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846
#define G    9.8
#define K    0.0175
#define R_E  6371008.8
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

struct flrange_flduration {
    double engthrust_val;
    int airbornspeed; int average_climspeed; int climtime; int cruisspeed; int average_climspeed_1000; 
    int descspeed; int desctime; int load_weight; int full_fusupp; int fucons_preTO; int climtime_1000;
    int fucons_TO; int fucons_desc; int fucons_final_land_taxi; int guarfusupp_unusfures; int midaverage_climspeed_1000;
    double midaverage_climspeed; double flrang_clim; double fucons_clim; double fucons_cruise;
    double req_engthrustcruise; double lifttodrag_ratio; double hourfucons; double spec_fuconsclim;
    double spec_fuconscruise; double rangcruise; double timecruise; double flrang_clim_1000;
    int flrange; int flduration; int flduration_h; int flduration_m;  
    } flight;

struct fltime_flangle_flspeed {
    int turn_time; int turn_time_m; int turn_time_s; int turn_roll; int turn_angle;
    int max_aircr_speed; int wind_angle; int magnetpath_angle; int aircr_speed; int wind_dir;
    int graund_speed; int drift_angle; int wind_speed; int speed_range; int time_range;
    int lateral_line; int flcurr_range; int flrem_range; int flight_track; int heading_corr;
    double turn_rad; double t; double mindist_checkpoint; double range_turnlead; double ny;
    double course_correction_curr; double course_correction_rem; double course_correction;
    double turn_speed;
} maneuver;

void nav_flcalc(int desctime, int full_fusupp,  int fucons_TO, int fucons_desc, int fucons_final_land_taxi, 
                         int guarfusupp_unusfures, int cruisspeed, double engthrust_val, int fucons_preTO, 
                         double spec_fuconsclim, int average_climspeed, int airbornspeed, int result_flrange[1], int result_flduration[3]) 
{
    flight.midaverage_climspeed_1000 = 0.5 * (airbornspeed + average_climspeed);
    flight.midaverage_climspeed = average_climspeed;
    flight.flrang_clim_1000 = (flight.midaverage_climspeed_1000 * 3.6) * ((flight.climtime_1000 / 3600) / 1000);    
    flight.climtime_1000 = flight.flrang_clim_1000 / flight.midaverage_climspeed_1000;
    flight.flrang_clim = flight.flrang_clim_1000 + (average_climspeed * 3.6) * (((flight.climtime - flight.climtime_1000) / 3600) / 1000);
    flight.climtime = flight.flrang_clim / average_climspeed;
    flight.fucons_clim = (spec_fuconsclim * engthrust_val) * (flight.climtime / 3600 ); 
    flight.fucons_cruise = full_fusupp - fucons_preTO - flight.fucons_TO - flight.fucons_clim - fucons_desc - fucons_final_land_taxi - guarfusupp_unusfures;
    flight.req_engthrustcruise = (flight.load_weight * G) / flight.lifttodrag_ratio;
    flight.hourfucons = (flight.spec_fuconscruise * flight.req_engthrustcruise) / cruisspeed;
    flight.rangcruise = flight.fucons_cruise / flight.hourfucons;
    flight.timecruise = flight.rangcruise / cruisspeed;
    flight.flrange = flight.flrang_clim_1000 + (average_climspeed * (flight.climtime - flight.climtime_1000) / 3600) + (cruisspeed * flight.timecruise) + (flight.descspeed * desctime / 3600);
    flight.flduration = flight.climtime + (flight.fucons_cruise / 1000 / flight.hourfucons * 3600) + desctime;
    flight.flduration_h = (int)flight.flduration / 3600;
    flight.flduration_m = (int)flight.flduration % 3600 / 60;

    resuit_flrange[0] = flight.flrange;
    result_flduration[0] = flight.flduration;
    result_flduration[1] = flight.flduration_h;
    result_flduration[2] = flight.flduration_m;
}





