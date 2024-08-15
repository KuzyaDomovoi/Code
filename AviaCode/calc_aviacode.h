#ifndef __CALC_AVIACODE_H__
#define __CALC_AVIACODE_H__

void kmh_to_knh(double airspeed_kmh, double result_knh[1]);
void knh_to_kmh(double airspeed_knh, double result_kmh[1]);
int nav_time(int fl_hours , int fl_minutes, int fl_seconds);
bool range2(float x, float a, float y);
bool input_verif_lat(int a, int b, float c, int res);
bool input_verif_lng(int a, int b, float c, int res);
void coord_transfer_deg(float deg, float result1[2], float result2[1]);
void coord_transfer_wgs84(float deg, float min, float sec, double res_lat1[1], double res_lng1[1], double res_lat2[1], double res_lng2[1]);
void calcfldist_bear(double lat1, double lng1, double lat2, double lng2, double result[4]);
void calcpoint_coord(double lat1, double lng1, double bearing, double dist, double result_cl2sl2[4]);
void calc_time_collision(double aircr_speed1, double aircr_speed2, double distance, double result_coll[1]);
void calc_time_catch(double aircr_speed1, double aircr_speed2, double distance, double result_catch[2]);
void flrange_duration_calc(int desctime, int full_fusupp, double fucons_preTO, double fucons_TO, double fucons_desc, 
                           double fucons_final_land_taxi, double guarfusupp_unusfures, int cruisspeed, double engthrust_val,  
                           double spec_fuconsclim, int average_climspeed, int airbornspeed, int descspeed,
                           double result_flrange[2], double result_flduration[2]);
void calc_turn(double aircr_speed, double turn_angle, double turn_roll, double result_turn[6]);
double calc_angle(double aircr_speed, double wind_speed, double path_angle, double wind_dir);
void calc_timecorrection(double aircr_speed, double max_aircr_speed, double time_range, double res_timecorr[2]);
void calc_trackcorrection(double lateral_line, double flight_track, double flcurr_range, double res_trackcorr[3]);
void calc_flduration(double ground_speed, double flight_dist, double result_flduration2[3]);

#endif
