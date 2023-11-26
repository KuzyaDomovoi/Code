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
    double turn_time; double turn_time_m; double turn_time_s; double turn_roll; double turn_angle;
    double max_aircr_speed; double wind_angle; double magnetpath_angle; double aircr_speed; double wind_dir;
    double ground_speed; double drift_angle; double wind_speed; double speed_range; double time_range;
    double lateral_line; double flcurr_range; double flrem_range; double flight_track; double heading_corr;
    double turn_rad; double t; double mindist_checkpoint; double range_turnlead; double ny;
    double course_correction_curr; double course_correction_rem; double course_correction;
    double turn_speed;
} maneuver;

void calc_turn(double aircr_speed, double turn_angle, double turn_roll, double result_turn[6]) 
{
    maneuver.turn_rad = pow(maneuver.aircr_speed / 3.6, 2) / (G * tan(maneuver.turn_roll * RAD));
    maneuver.range_turnlead = K * maneuver.turn_rad * maneuver.turn_angle;
    maneuver.turn_time = (2 * M_PI * maneuver.aircr_speed / 3.6) / (G * tan(maneuver.turn_roll * RAD)) * maneuver.turn_angle / 360;
    maneuver.turn_time_m = (maneuver.turn_time / 60) % 60;
    maneuver.turn_time_s = maneuver.turn_time % 60;
    maneuver.ny = 1 / cos(maneuver.turn_roll * RAD);
    maneuver.turn_speed = maneuver.turn_angle / maneuver.turn_time;

    result_turn[0] = maneuver.turn_rad
    result_turn[1] = maneuver.turn_time_m;
    result_turn[2] = maneuver.turn_time_s;
    result_turn[3] = maneuver.turn_speed;
    result_turn[4] = maneuver.ny;
    result_turn[5] = maneuver.range_turnlead 
}

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
    resuit_graundspeed[0] = flight.ground_speed;
    
}

double calc_angle(double aircr_speed, double wind_speed, double magnetpath_angle, double wind_dir) {
    if(maneuver.wind_dir == maneuver.magnetpath_angle) {
        maneuver.drift_angle = 0;
        maneuver.ground_speed = maneuver.aircr_speed + maneuver.wind_speed;
        printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.ground_speed);
        return 0;
    }
    if(maneuver.wind_dir < maneuver.magnetpath_angle) {
        maneuver.wind_angle = 360 + maneuver.wind_dir - maneuver.magnetpath_angle;
    } else
        maneuver.wind_angle = maneuver.wind_dir - maneuver.magnetpath_angle;
    if(maneuver.wind_angle == 180 || maneuver.wind_angle == 0 || maneuver.wind_angle == 360) {
        maneuver.drift_angle = 0;
        maneuver.ground_speed = maneuver.aircr_speed - maneuver.wind_speed;
        printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.ground_speed);
        return 0;
    }
    if(range(0, maneuver.magnetpath_angle, 180) && range(0, maneuver.wind_dir, 180))
        maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle) * RAD);
    if(range(0, maneuver.magnetpath_angle, 180) && range(181, maneuver.wind_dir, 360))
        maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle) * RAD);
    if(range(181, maneuver.magnetpath_angle, 360) && range(0, maneuver.wind_dir, 180))
        maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle) * RAD);
    if(range(181, maneuver.magnetpath_angle, 360) && range(181, maneuver.wind_dir, 360))
    maneuver.t = (double)maneuver.wind_speed / maneuver.aircr_speed * sin((maneuver.wind_angle) * RAD);
    maneuver.drift_angle = rint(asin(maneuver.t) * DEG);
    maneuver.ground_speed = maneuver.aircr_speed * cos(maneuver.drift_angle * RAD) + maneuver.wind_speed * cos(maneuver.wind_angle * RAD);
    maneuver.heading_corr = maneuver.magnetpath_angle - maneuver.drift_angle;
    printf("\n   угол сноса = %d°\n   курс с учетом УС = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.heading_corr, maneuver.ground_speed);
    return 0;
}

double calc_trackcorrection(double lateral_line, double flight_track, double flcurr_range) {            
    maneuver.flrem_range = maneuver.flight_track - maneuver.flcurr_range;
    maneuver.course_correction_curr = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * DEG);
    maneuver.course_correction_rem = (atan((double)maneuver.lateral_line / maneuver.flrem_range) * DEG);
    maneuver.course_correction = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * DEG) + (atan((double)maneuver.lateral_line / maneuver.flrem_range) * DEG);
    printf("   при ЛБУ = %d км:\n      боковое уклонение = УС = %.f°\n      дополнительная ПК = %.f°\n      полная ПК = %.f°\n", 
            maneuver.lateral_line, maneuver.course_correction_curr, maneuver.course_correction_rem, maneuver.course_correction);
    return 0;
}
