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
    int ground_speed; int drift_angle; int wind_speed; int speed_range; int time_range;
    int lateral_line; int flcurr_range; int flrem_range; int flight_track; int heading_corr;
    double turn_rad; double t; double mindist_checkpoint; double range_turnlead; double ny;
    double course_correction_curr; double course_correction_rem; double course_correction;
    double turn_speed;
} maneuver;

void navigation(int cruisspeed, int result_flrange[1]) 
{
    flight.ground_speed; // func  
    flight.rangcruise; // func
    flight.timecruise = flight.rangcruise / cruisspeed;
    flight.flrange = cruisspeed * flight.timecruise;
    flight.flduration = flight.flrange / cruisspeed;
    
    flight.flduration_h = (int)flight.flduration / 3600;
    flight.flduration_m = (int)flight.flduration % 3600 / 60;

    resuit_flrange[0] = flight.flrange;
    resuit_bering[0] = ; // func?
    resuit_graundspeed[0] = graundspeed;
    resuit_
}





