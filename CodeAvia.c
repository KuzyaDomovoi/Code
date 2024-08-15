#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <tgmath.h>

#define M_PI 3.14159265358979323846
#define G    9.80665
#define R_E  6371008.8
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI
#define KNH  1.852
#define kHph 3.2808
#define kPpa 133.322
#define M    29
#define R    8.31447
#define T0   273.15 // 0 K;
#define t0   15 // 288.15 K;
#define P0   101.325 // 760 мм рт ст;
#define p0   1.225
#define K    1.4

void kmh_to_knh(double airspeed_kmh, double result_knh[1]) {
    double airspeed_knh = airspeed_kmh / KNH;

    result_knh[0] = airspeed_knh;
}

void knh_to_kmh(double airspeed_knh, double result_kmh[1]) {
    double airspeed_kmh = airspeed_knh * KNH;

    result_kmh[0] = airspeed_kmh;
}

void hm_to_hph(double alt_m, double result_hph[1]) {
    double alt_ph = alt_m * kHph;

    result_hph[0] = alt_ph;
}

void hph_to_hm(double alt_hph, double result_hm[1]) {
    double alt_m = alt_hph / kHph;

    result_hm[0] = alt_m;
}

void ias_to_tas(double airspeed_kmh, double aircr_alt, double airtemp_h, double result_tas[1]) {
    double tH = airtemp_h - (6.5 * (aircr_alt / 1000));
    double pH = P0 * exp(- (M * G * (aircr_alt / 1000)) / (R * T0));
    double p = (pH * M) / (R * (T0 + tH));
    double tas = airspeed_kmh / sqrt(p / p0);
    
    result_tas[0] = tas;
}

int nav_time(int fl_hours , int fl_minutes, int fl_seconds) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
       
    int year = tm.tm_year + 1900;
    int mon = tm.tm_mon + 1;
    int day = tm.tm_mday;

    int hours = tm.tm_hour;
    int minutes = tm.tm_min;
    int seconds = tm.tm_sec;

    while(1) {
        t = time(NULL);
        tm = *localtime(&t);
        printf("Время текущее: %02d/%02d/%d  %02d:%02d:%02d  ", 
                day, mon, year, hours, minutes, seconds);
        fflush(stdout);
        seconds++;
        if(seconds == 60) {
            minutes += 1;
            seconds = 0;
        }
        if(minutes == 60) {
            hours += 1;
            minutes = 0;
        }
        if(hours == 24) {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }

        int year1 = tm.tm_year + 1900;
        int mon1 = tm.tm_mon + 1;
        int day1 = tm.tm_mday;

        int c_time = hours * 3600 + minutes * 60 + seconds;
        int fl_time = fl_hours * 3600 + fl_minutes * 60 + fl_seconds;
        int res_time = c_time + fl_time;

        int res_hours = res_time / 3600;
        int res_minutes = res_time / 60 % 60;
        int res_seconds = res_time % 60;

        int mdays;
        if(mon1 == 1 || mon1 == 3 || mon1 == 5 || mon1 == 7 || mon1 == 8 || mon1 == 10 || mon1 == 12) {
            mdays = 31;
        }
        if(mon1 == 4 || mon1 == 6 || mon1 == 9 || mon1 == 11) {
            mdays = 30;
        }
        if(mon1 == 2) {
            if((year1 % 400 || year1 % 4) == 0) {
                mdays = 29;
            } else
                mdays = 28;
        }
        
        day1 += res_hours / 24;
                if(day1 > mdays) {
                day1 %= mdays;
            }
        mon1 += res_hours / 24 / mdays;
            if(mon1 > 12) {
                mon1 %= 12;
            }
        int yhours;
        if((year1 % 400 || year1 % 4) == 0) {
            yhours = 8784; // 366 ydays
        } else
            yhours = 8760; // 365 ydays;
        if(res_hours > yhours) { 
            year1 += ceil((double)res_hours / 24 / mdays / 12);
        } else year1 += res_hours / 24 / mdays % 12; // is correct for flight-durance less than 1440 hours only;
        
        if(res_hours >= 24) {
            printf("Ожидаемое прибытие: %02d/%02d/%d  %02d:%02d:%02d\r", 
                    day1, mon1, year1, res_hours % 24, res_minutes, res_seconds);
        } else
            printf("Ожидаемое прибытие: %02d/%02d/%d  %02d:%02d:%02d\r", 
                    day1, mon1, year1, res_hours, res_minutes, res_seconds);
        fflush(stdout);
        res_seconds++;
        if(res_seconds == 60) {
            res_minutes += 1;
            res_seconds = 0;
        }
        if(res_minutes == 60) {
            res_hours += 1;
            res_minutes = 0;
        }
        if(res_hours == 24) {
            res_hours = 0;
            res_minutes = 0;
            res_seconds = 0;
        }
        sleep(1);
    }
	return 0;
}

struct geo_lat {
    double lat;
    float sec; int min;
    int deg; 
    double initial_bearing;
    float fldist;
} lat_1;

struct geo_lng {
    double lng;
    float sec; int min;
    int deg;
} lng_1;

struct geo_lat lat_2;
struct geo_lng lng_2;

bool range2(float x, float a, float y) {
    if(a < x || a > y)
        return true;
    return false;
}

bool input_verif_lat(int a, int b, float c, int res) {
    if(res != 3) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-90, a, 90)) {
        printf("\nIncorrect input! Range of latitude is -90...90\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59.99)) {
        printf("\nIncorrect input! Range of min and sec is 0...59.99\n");
        return true;
    }
    if(range2(-89, a, 89) && (b > 0 || c > 0)) {
        printf("\nIncorrect input! If the latitude has value -90 or 90, the values of min and sec should be 00 only\n");
        return true;
    } else return false;
}

bool input_verif_lng(int a, int b, float c, int res) {
    if(res != 3) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-180, a, 180)) {
        printf("\nIncorrect input! Range of latitude is -180...180\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59.99)) {
        printf("\nIncorrect input! Range of min and sec is 0...59.99\n");
        return true;
    }
    if(range2(-179, a, 179) && (b > 0 || c > 0)) {
        printf("\nIncorrect input! If the longitude has value -180 or 180, the values of min and sec should be 00 only\n");
        return true;
    } else return false;
}

void coord_transfer_deg(float deg, float result1[2], float result2[1]) {
    int dd = trunc(deg);
    int mm = trunc((deg - dd) * 60);
    float ss = ((deg - dd) * 60 - mm) * 60;

    result1[0] = dd;
    result1[1] = abs(mm);
    result2[0] = fabs(ss);
}

void coord_transfer_wgs84(float deg, float min, float sec, double res_lat1[1], double res_lng1[1], double res_lat2[1], double res_lng2[1]) {
    float lat1, lng1, lat2, lng2;

    if(lat_1.deg < 0) {
        lat1 = -1 * (abs(lat_1.deg) + (lat_1.min * 60.0 + lat_1.sec) / 3600.0);
    } else
        lat1 = lat_1.deg + (lat_1.min * 60.0 + lat_1.sec) / 3600.0;
    if(lng_1.deg < 0) {
        lng1 = -1 * (abs(lng_1.deg) + (lng_1.min * 60.0 + lng_1.sec) / 3600.0);
    } else
        lng1 = lng_1.deg + (lng_1.min * 60.0 + lng_1.sec) / 3600.0;
    if(lat_2.deg < 0) {
        lat2 = -1 * (abs(lat_2.deg) + (lat_2.min * 60.0 + lat_2.sec) / 3600.0);
    } else
        lat2 = lat_2.deg + (lat_2.min * 60.0 + lat_2.sec) / 3600.0;
    if(lng_2.deg < 0) {
        lng2 = -1 * (abs(lng_2.deg) + (lng_2.min * 60.0 + lng_2.sec) / 3600.0);
    } else
        lng2 = lng_2.deg + (lng_2.min * 60.0 + lng_2.sec) / 3600.0;

    res_lat1[0] = lat1;
    res_lng1[0] = lng1;
    res_lat2[0] = lat2;
    res_lng2[0] = lng2;
}

void calcfldist_bear(double lat1, double lng1, double lat2, double lng2, double result[4]) {
    double initial_bearing;
    double end_bearing;

    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);

    double delta_lng = lng_2.lng - lng_1.lng;
    double delta_lng2 = lng_1.lng - lng_2.lng;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);
    double cdelta_lng2 = cos(delta_lng2);
    double sdelta_lng2 = sin(delta_lng2);

    double y = sdelta_lng * cl2;
    double x = cl1 * sl2 - sl1 * cl2 * cdelta_lng;
    double angledeg = atan2(y, x) * DEG;
    if(angledeg > 0) {
       initial_bearing = angledeg;
    } else initial_bearing = angledeg + 360;

    double y2 = sdelta_lng2 * cl1;
    double x2 = cl2 * sl1 - sl2 * cl1 * cdelta_lng2;
    double angledeg2 = atan2(y2, x2) * DEG;
    if(angledeg2 > 180) {
       end_bearing = angledeg2;
    } else end_bearing = angledeg2 + 180;

    y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad = atan2(y, x);
    double flight_dist = anglerad * R_E;
    double onegrad_dist = flight_dist / fabs(end_bearing - initial_bearing);

    result[0] = flight_dist;
    result[1] = initial_bearing;
    result[2] = end_bearing;
    result[3] = onegrad_dist;
}

void calcpoint_coord(double lat1, double lng1, double bearing, double dist, double result_cl2sl2[4]) {
    double end_bearing;

    double cl1 = cos(lat1 * RAD);
    double sl1 = sin(lat1 * RAD);
    double cbear = cos(bearing * RAD);
    double sbear = sin(bearing * RAD);
    double cdist = cos(dist / R_E);
    double sdist = sin(dist / R_E);

    double lat2 = asin(sl1 * cdist + cl1 * sdist * cbear) * DEG;
    double cl2 = cos(lat2 * RAD);
    double sl2 = sin(lat2 * RAD);
    double lng2 = lng1 + atan2(sbear * sdist * cl1, cdist - sl1 * sl2) * DEG;

    double delta_lng2 = lng1 * RAD - lng2 * RAD;
    double sdelta_lng2 = sin(delta_lng2);
    double cdelta_lng2 = cos(delta_lng2);

    double y = sdelta_lng2 * cl1;
    double x = cl2 * sl1 - sl2 * cl1 * cdelta_lng2;
    double angledeg = atan2(y, x) * DEG;
    if(angledeg > 180) {
       end_bearing = angledeg;
    } else end_bearing = angledeg + 180;
    double onegrad_dist = dist / fabs(end_bearing - bearing);

    result_cl2sl2[0] = lat2;
    result_cl2sl2[1] = lng2;
    result_cl2sl2[2] = end_bearing;
    result_cl2sl2[3] = onegrad_dist;
}

struct flrange_flduration {
    int climtime; double cruisspeed; int fuweight; double descspeed; double desctime; double req_engthrustcruise; double finalrange; double apralt;
    double lifttodrag_ratio; double flrange; double alt; double climalt; double ias; double tas; double load_weight; double average_desctime;
    int flduration; int flduration_h; int flduration_m; int flduration_s; double airtemp_h; double cruistime; double finalspeed; double average_climspeed;
    double cruisalt; double descrange; double fastspeed; double cruisrange; double average_kmfucons; double mfufinal; double average_climtime; double finaltime;
    double average_descspeed; double initial_climspeed; double climrange; double fucons_cruise; double average_verticalclimspeed; double average_verticaldescspeed;
} flight;

struct fltime_flangle_flspeed {
    double turn_roll; double turn_angle; double max_aircr_speed; double wind_angle; double path_angle;
    double aircr_speed; double wind_dir; double ground_speed; double drift_angle; double wind_speed; 
    double speed_range; double time_range; double lateral_line; double flcurr_range; double flrem_range; 
    double flight_track; double heading_corr; double turn_rad; double t; double mindist_checkpoint; double time_cathch;
    double range_turnlead; double ny; double course_correction_curr; double course_correction_rem; double distance;
    double course_correction; double turn_speed; double aircr_speed1; double aircr_speed2; double time_collision; 
    int hours; int minutes; int seconds; int turn_time; int turn_time_m; int turn_time_s; double lineal_preemption;
} maneuver;

void calc_time_collision(double aircr_speed1, double aircr_speed2, double distance, double result_coll[1]) {
    double time_collision = distance / (aircr_speed1 + aircr_speed2) * 3600;

    result_coll[0] = time_collision;
}

void calc_time_catch(double aircr_speed1, double aircr_speed2, double distance, double result_catch[2]) {
    double time_catch = distance / (aircr_speed1 - aircr_speed2) * 3600;

    result_catch[0] = aircr_speed1 - aircr_speed2;
    result_catch[1] = time_catch;
}

void flrange_duration_calc(double lifttodrag_ratio, double load_weight, double req_engthrustcruise, double fastspeed, double initial_climspeed, 
                           int climtime, double average_verticalclimspeed, double average_verticaldescspeed, double average_climspeed, double apralt,
                           double cruisspeed, double descspeed, double desctime, double average_desctime, double finaltime, double finalrange, double fuweight,
                           double result_flrange[1], double result_flduration[2]) {
    printf("\n  аэродинамическое качество с-та: ");
    if(scanf("%lf", &flight.lifttodrag_ratio) != 1) {
        printf("\nIncorrect input!\n");
        exit(1);
    
    }printf("  заправка топливом, кг: ");
    if(scanf("%d", &flight.fuweight) != 1) {
        printf("\nIncorrect input!\n");
        exit(2);
    }
    printf("  взлетный вес самолета, кг: ");
    if(scanf("%lf", &flight.load_weight) != 1) {
        printf("\nIncorrect input!\n");
        exit(3);
    }
    printf("  набор/изменение высоты, м: ");
    if(scanf("%lf", &flight.climalt) != 1) {
        printf("\nIncorrect input!\n");
        exit(4);
    }
    printf("  скорость в наборе высоты, км/ч: ");
    if(scanf("%lf", &flight.average_climspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(5);
    }
    printf("  средняя вертикальная скорость набора высоты, м/с: ");
    if(scanf("%lf", &flight.average_verticalclimspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(6);
    }
    printf("  скорость по мрш, км/ч: ");
    if(scanf("%lf", &flight.cruisspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(7);
    }
    printf("  крейсерская скорость полета, км/ч: ");
    if(scanf("%lf", &flight.fastspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(8);
    }
    printf("  километровый расход топлива по мрш, кг: ");
    if(scanf("%lf", &flight.average_kmfucons) != 1) {
        printf("\nIncorrect input!\n");
        exit(9);
    }
    printf("  скорость на снижении, км/ч: ");
    if(scanf("%lf", &flight.descspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(10);
    }
    printf("  средняя вертикальная скорость на снижении, м/с: ");
    if(scanf("%lf", &flight.average_verticaldescspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(11);
    }
    printf("  скорость на глиссаде, км/ч: ");
    if(scanf("%lf", &flight.finalspeed) != 1) {
        printf("\nIncorrect input!\n");
        exit(12);
    }
    printf("  расстояние по кругу, км: ");
    if(scanf("%lf", &flight.finalrange) != 1) {
        printf("\nIncorrect input!\n");
        exit(13);
    }
      
    flight.average_climtime = flight.climalt / flight.average_verticalclimspeed;
    flight.average_desctime = flight.apralt / flight.average_verticaldescspeed;
    flight.cruisspeed = 1.31 * flight.fastspeed;
    flight.mfufinal = 1.3 * flight.average_kmfucons * flight.finalrange;
    flight.cruisrange = (flight.fuweight - flight.mfufinal) / flight.average_kmfucons;
    flight.average_descspeed = (flight.descspeed + flight.finalspeed) / 2;
    flight.climrange = flight.average_climspeed * (flight.average_climtime / 3600);
    flight.descrange = flight.average_descspeed * (flight.average_desctime / 3600);
    flight.cruistime = flight.cruisrange / flight.cruisspeed;
    flight.finaltime = flight.finalrange / flight.finalspeed;
    flight.flrange = flight.climrange + flight.cruisrange + flight.descrange + flight.finalrange;
    flight.flduration = flight.average_climtime + (flight.cruistime * 3600) + flight.average_desctime + (flight.finaltime * 3600);
    flight.flduration_h = flight.flduration / 3600;
    flight.flduration_m = flight.flduration % 3600 / 60;

    result_flrange[0] = flight.flrange;
    result_flduration[0] = flight.flduration_h;
    result_flduration[1] = flight.flduration_m;
}

void calc_turn(double aircr_speed, double turn_angle, double turn_roll, double result_turn[7]) {
    if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500) {
        printf("\nIncorrect input! The unreal speed for an aircraft or for the wind!\n");
        exit(1);
    }
    if(maneuver.turn_roll > 83) {
        printf("\nIncorrect input! The turn_roll can't be more than 83°!\n");
        exit(2);
    }
    maneuver.turn_rad = pow(maneuver.aircr_speed / 3.6, 2) / (G * tan(maneuver.turn_roll * RAD));
    maneuver.range_turnlead = RAD * maneuver.turn_rad * maneuver.turn_angle;   
    if(maneuver.turn_angle < 90) {
        maneuver.lineal_preemption = maneuver.turn_rad * tan(maneuver.turn_angle * RAD/ 2);
    } else
        maneuver.lineal_preemption = maneuver.turn_rad;
    maneuver.turn_time = (2 * M_PI * maneuver.aircr_speed / 3.6) / (G * tan(maneuver.turn_roll * RAD)) * maneuver.turn_angle / 360;
    maneuver.turn_time_m = (maneuver.turn_time / 60) % 60;
    maneuver.turn_time_s = maneuver.turn_time % 60;
    maneuver.ny = 1 / cos(maneuver.turn_roll * RAD);
    maneuver.turn_speed = maneuver.turn_angle / maneuver.turn_time;

    result_turn[0] = maneuver.turn_rad;
    result_turn[1] = maneuver.turn_time_m;
    result_turn[2] = maneuver.turn_time_s;
    result_turn[3] = maneuver.turn_speed;
    result_turn[4] = maneuver.ny;
    result_turn[5] = maneuver.range_turnlead;
    result_turn[6] = maneuver.lineal_preemption;
}

double calc_angle(double aircr_speed, double wind_speed, double path_angle, double wind_dir) {
    if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500 || maneuver.wind_speed < 0 || maneuver.wind_speed > 100) {
        printf("\nIncorrect input! The unreal speed for an aircraft or for the wind!\n");
        return 0;
    }
    if(maneuver.path_angle < 0 || maneuver.path_angle > 360 || maneuver.wind_dir < 0 || maneuver.wind_dir > 360) {
        printf("\nIncorrect input! Angle can't be less 0° or more than 360°\n");
        return 0;
    }
    if(maneuver.wind_dir == maneuver.path_angle) {
        maneuver.drift_angle = 0;
        maneuver.ground_speed = maneuver.aircr_speed + (maneuver.wind_speed * 3.6);
        printf("\nугол сноса = %.1f°\nпутевая скорость = %.f км/ч\nскорость ветра = %.f км/ч\n",
                maneuver.drift_angle, maneuver.ground_speed, maneuver.wind_speed * 3.6);
        return 0;
    }
    if(maneuver.wind_dir < maneuver.path_angle) {
        maneuver.wind_angle = 360 + maneuver.wind_dir - maneuver.path_angle;
    } else
        maneuver.wind_angle = maneuver.wind_dir - maneuver.path_angle;
    if(maneuver.wind_angle == 180 || maneuver.wind_angle == 0 || maneuver.wind_angle == 360) {
        maneuver.drift_angle = 0;
        maneuver.ground_speed = maneuver.aircr_speed - (maneuver.wind_speed * 3.6);
        printf("\nугол сноса = %.1f°\nпутевая скорость = %.f км/ч\nскорость ветра = %.f км/ч\n", 
                maneuver.drift_angle, maneuver.ground_speed, maneuver.wind_speed * 3.6);
        return 0;
    } else
        maneuver.t = (maneuver.wind_speed * 3.6) / maneuver.aircr_speed * sin((maneuver.wind_angle) * RAD);
        maneuver.drift_angle = asin(maneuver.t) * DEG;
        maneuver.ground_speed = maneuver.aircr_speed * cos(maneuver.drift_angle * RAD) + (maneuver.wind_speed * 3.6) * cos(maneuver.wind_angle * RAD);
        maneuver.heading_corr = maneuver.path_angle - maneuver.drift_angle;
        printf("\nугол сноса = %.1f°\nкурс с учетом УС = %.1f°\nпутевая скорость = %.f км/ч\nскорость ветра = %.f км/ч\n", 
                maneuver.drift_angle, maneuver.heading_corr, maneuver.ground_speed, maneuver.wind_speed * 3.6);
        return 0;
}

void calc_timecorrection(double aircr_speed, double max_aircr_speed, double time_range, double res_timecorr[2]) {
    printf("\nРасчет минимального расстояния для возможного погашения опоздания или избытка времени\n");
    printf("\n   Введи последовательно:\nприб скорость полета в км/ч\nмакс приб скорость в км/ч\n" 
           "макс возможный избыток или недостаток времени в сек\n");
    if(scanf("%lf %lf %lf", &maneuver.aircr_speed, &maneuver.max_aircr_speed, &maneuver.time_range) != 3) {
        printf("\nIncorrect input!\n");
        exit(1);
    }
    if(maneuver.max_aircr_speed < maneuver.aircr_speed) {
        printf("\nIncorrect input! The max_aircr_speed can't be less than aircr_speed!\n");
        exit(2); 
    } 
    maneuver.speed_range = maneuver.max_aircr_speed - maneuver.aircr_speed;
    maneuver.mindist_checkpoint = (maneuver.aircr_speed * maneuver.max_aircr_speed / maneuver.speed_range * maneuver.time_range / 3600);
    
    res_timecorr[0] = maneuver.speed_range;
    res_timecorr[1] = maneuver.mindist_checkpoint;
}

void calc_trackcorrection(double lateral_line, double flight_track, double flcurr_range, double res_trackcorr[3]) { 
    printf("\nРасчет поправки в курс по расстоянию и боковому уклонению\n");
    printf("\n   Введи линейное боковое уклонение в км: ");
    if(scanf("%lf", &maneuver.lateral_line) != 1) {
        printf("\nIncorrect input!\n");
        exit(1);
    }
    printf("   Введи общее расстояние до РТ в км: ");
    if(scanf("%lf", &maneuver.flight_track) != 1) {
        printf("\nIncorrect input!\n");
        exit(2);
    }
    printf("   Введи пройденное/оставшееся расстояние до РТ в км: ");
    if(scanf("%lf", &maneuver.flcurr_range) != 1) {
        printf("\nIncorrect input!\n");
        exit(3);
    }          
    maneuver.flrem_range = maneuver.flight_track - maneuver.flcurr_range;
    maneuver.course_correction_curr = (atan(maneuver.lateral_line / maneuver.flcurr_range) * DEG);
    maneuver.course_correction_rem = (atan(maneuver.lateral_line / maneuver.flrem_range) * DEG);
    maneuver.course_correction = (atan(maneuver.lateral_line / maneuver.flcurr_range) * DEG) + (atan(maneuver.lateral_line / maneuver.flrem_range) * DEG);
    
    res_trackcorr[0] = maneuver.course_correction_curr;
    res_trackcorr[1] = maneuver.course_correction_rem;
    res_trackcorr[2] = maneuver.course_correction;
}

void calc_flduration(double ground_speed, double flight_dist, double result_flduration2[3]) {
    flight.flduration = flight_dist / maneuver.ground_speed * 3.6;
    flight.flduration_h = flight.flduration / 3600;
    flight.flduration_m = flight.flduration / 60 % 60;
    flight.flduration_s = flight.flduration % 60;

    result_flduration2[0] = flight.flduration_h;
    result_flduration2[1] = flight.flduration_m;
    result_flduration2[2] = flight.flduration_s;
}

int main(void)
{
    int item, res = 0;
    double lat1, lat2, lng1, lng2;
    double result_flrange[1], result_flduration[2];
    double result_flduration2[3];
    double result_turn[7];
    double res_lat1[1], res_lng1[1], res_lat2[1], res_lng2[1];
    double result_db[4];
    double result_cl2sl2[4];
    double result_knh[1], result_kmh[1];
    double result_hph[1], result_hm[1];  
    double result_tas[1], result_ias[1];
    double result_coll[1], result_catch[2];
    double res_timecorr[2];
    double res_trackcorr[3];
    float lat_res1[2], lng_res1[2], lat_res2[1], lng_res2[1];
    float lat_res1_1[2], lng_res1_1[2], lat_res2_2[1], lng_res2_2[1];
    
    printf("\n1. Расчет дальности и продолжительности полета\n"
             "2. Расчет расстояния между двумя точками\n"
             "3. Расчет навигационных данных\n"
             "4. Преобразование координат\n"
             "5. Расчеты маневрирования\n"
             "6. Выход\n");
    printf("   Выбери действие: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError! Input is out of range list!\n");
        return 0;
    }
    switch(item) {
    case 1:
        printf("Расчет дальности и продолжительности полета\n");
        flrange_duration_calc(flight.lifttodrag_ratio, flight.load_weight, flight.req_engthrustcruise, flight.fastspeed, flight.initial_climspeed, 
                              flight.climtime, flight.average_verticalclimspeed, flight.average_verticaldescspeed, flight.average_climspeed,
                              flight.cruisspeed, flight.descspeed, flight.desctime, flight.average_desctime, flight.finaltime, flight.finalrange, flight.fuweight,
                              flight.apralt, result_flrange, result_flduration);
        printf("\nДальность полета = %.1f км\nПродолжительность полета = %02.f ч %02.f мин\n", 
                result_flrange[0], result_flduration[0], result_flduration[1]);
        return 0;
    case 2:
        printf("\nРасчет расстояния между двумя точками по их координатам\n");
        printf("\n   1. Расчет расстояния по координатам WGS-84 формата гг мм сс.сс\n"
                 "   2. Расчет расстояния по координатам WGS-84 формата гг.гггггг\n"
                 "   3. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! Input is out of range list!!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nРасчет расстояния по координатам WGS-84 формата гг мм сс.сс\n");
            printf("\n   Введи координаты гг мм сс.сс широты первой точки: ");
            res = scanf("%d %d %f", &lat_1.deg, &lat_1.min, &lat_1.sec);
            if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, res) != 0)
                return 0;
            printf("   Введи координаты ггг мм сс.сс долготы первой точки: ");
            res = scanf("%d %d %f", &lng_1.deg, &lng_1.min, &lng_1.sec);
            if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, res) != 0)
                return 0;
            printf("\n   Введи координаты гг мм сс.сс широты второй точки: ");
            res = scanf("%d %d %f", &lat_2.deg, &lat_2.min, &lat_2.sec);
            if(input_verif_lat(lat_2.deg, lat_2.min, lat_2.sec, res) != 0)
                return 0;
            printf("   Введи координаты ггг мм сс.сс долготы второй точки: ");
            res = scanf("%d %d %f", &lng_2.deg, &lng_2.min, &lng_2.sec);
            if(input_verif_lng(lng_2.deg, lng_2.min, lng_2.sec, res) != 0)
                return 0;
            coord_transfer_wgs84(lat_1.deg, lat_1.min, lat_1.sec, res_lat1, res_lng1, res_lat2, res_lng2);
            coord_transfer_wgs84(lat_2.deg, lat_2.min, lat_2.sec, res_lat1, res_lng1, res_lat2, res_lng2);
            calcfldist_bear(res_lat1[0], res_lng1[0], res_lat2[0], res_lng2[0], result_db);
            printf("\nПервая точка: lat   %f°\n              lng   %f°\n", res_lat1[0], res_lng1[0]);
            printf("Вторая точка: lat   %f°\n              lng   %f°\n", res_lat2[0], res_lng2[0]);
            printf("\nРасстояние = %.1f м\nНачальный азимут = %.6f°\nКонечный азимут = %.6f°\nНа %.f м 1° изменения азимута\n", 
                    result_db[0], result_db[1], result_db[2], result_db[3]);
            return 0;
        case 2:
            printf("\nРасчет расстояния по координатам WGS-84 формата гг.гггггг\n");
            printf("\n   Введи координаты гг.гггггг широты первой точки: ");
            if(scanf("%lf", &lat_1.lat) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи координаты гг.гггггг долготы первой точки: ");
            if(scanf("%lf", &lng_1.lng) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("\n   Введи координаты гг.гггггг широты второй точки: ");
            if(scanf("%lf", &lat_2.lat) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи координаты гг.гггггг долготы второй точки: ");
            if(scanf("%lf", &lng_2.lng) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            coord_transfer_deg(lat_1.lat, lat_res1, lat_res2);
            coord_transfer_deg(lng_1.lng, lng_res1, lng_res2);
            coord_transfer_deg(lat_2.lat, lat_res1_1, lat_res2_2);
            coord_transfer_deg(lng_2.lng, lng_res1_1, lng_res2_2);

            if(lat_res1[0] < 0 && lng_res1[0] < 0) {
                printf("\nПервая точка: lat  %03.f° %02.f' %05.2f''\n              lng %04.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
            if(lat_res1[0] < 0) {
                printf("\nПервая точка: lat  %03.f° %02.f' %05.2f''\n             lng  %03.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
            if(lng_res1[0] < 0) {
                printf("\nПервая точка: lat   %02.f° %02.f' %05.2f''\n              lng %04.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
                printf("\nПервая точка: lat   %02.f° %02.f' %05.2f''\n              lng  %03.f° %02.f' %05.2f''\n", 
                        lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);

            if(lat_res1_1[0] < 0 && lng_res1_1[0] < 0) {
                printf("Вторая точка: lat  %03.f° %02.f' %05.2f''\n              lng %04.f° %02.f' %05.2f''\n", 
                    lat_res1_1[0], lat_res1_1[1], lat_res2_2[0], lng_res1_1[0], lng_res1_1[1], lng_res2_2[0]);
            } else
            if(lat_res1_1[0] < 0) {
                printf("Вторая точка: lat  %03.f° %02.f' %05.2f''\n              lng  %03.f° %02.f' %05.2f''\n", 
                    lat_res1_1[0], lat_res1_1[1], lat_res2_2[0], lng_res1_1[0], lng_res1_1[1], lng_res2_2[0]);
            } else
            if(lng_res1_1[0] < 0) {
                printf("Вторая точка: lat   %02.f° %02.f' %05.2f''\n              lng %04.f° %02.f' %05.2f''\n", 
                    lat_res1_1[0], lat_res1_1[1], lat_res2_2[0], lng_res1_1[0], lng_res1_1[1], lng_res2_2[0]);
            } else
                printf("Вторая точка: lat   %02.f° %02.f' %05.2f''\n              lng  %03.f° %02.f' %05.2f''\n", 
                        lat_res1_1[0], lat_res1_1[1], lat_res2_2[0], lng_res1_1[0], lng_res1_1[1], lng_res2_2[0]);

            calcfldist_bear(lat_1.lat, lng_1.lng, lat_2.lat, lng_2.lng, result_db);
            printf("\nРасстояние = %.1f м\nНачальный азимут = %.6f°\nКонечный азимут = %.6f°\nНа %.f м 1° изменения азимута\n", 
                    result_db[0], result_db[1], result_db[2], result_db[3]);
            return 0;
        case 3:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 3:
        printf("\nРасчет начальных навигационных данных\n");
        printf("\n   1. Расчет по координатам WGS-84 формата гг мм сс.сс\n"
                 "   2. Расчет по координатам WGS-84 формата гг.гггггг\n"
                 "   3. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! Input is out of range list!!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\n   Введи координаты гг мм сс.сс широты первой точки: ");
            res = scanf("%d %d %f", &lat_1.deg, &lat_1.min, &lat_1.sec);
            if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, res) != 0)
                return 0;
            printf("   Введи координаты ггг мм сс.сс долготы первой точки: ");
            res = scanf("%d %d %f", &lng_1.deg, &lng_1.min, &lng_1.sec);
            if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, res) != 0)
                return 0;
            printf("   Введи дальность до второй точки в м: ");
            if(scanf("%f", &lat_1.fldist) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи истинный курс на вторую точку в °: ");
            if(scanf("%lf", &maneuver.path_angle) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи приборную скорость самолета в км/ч: ");
            if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи направление ветра в °: ");
            if(scanf("%lf", &maneuver.wind_dir) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи скорость ветра в м/с: ");
            if(scanf("%lf", &maneuver.wind_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            coord_transfer_wgs84(lat_1.deg, lat_1.min, lat_1.sec, res_lat1, res_lng1, res_lat2, res_lng2);
            calcpoint_coord(res_lat1[0], res_lng1[0], maneuver.path_angle, lat_1.fldist, result_cl2sl2);
            coord_transfer_deg(result_cl2sl2[0], lat_res1, lat_res2);
            coord_transfer_deg(result_cl2sl2[1], lng_res1, lng_res2);
            printf("\nПервая точка: lat %4d° %02d' %05.2f''\n              lng %4d° %02d' %05.2f''\n",
                    lat_1.deg, lat_1.min, lat_1.sec, lng_1.deg, lng_1.min, lng_1.sec);
            printf("Вторая точка: lat   %02.f° %02.f' %05.2f''\n              lng   %02.f° %02.f' %05.2f''\n\nКонечный азимут = %.6f°\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0], result_cl2sl2[2]);
            calc_angle(maneuver.aircr_speed, maneuver.wind_speed, maneuver.path_angle, maneuver.wind_dir);
            calc_flduration(maneuver.ground_speed, lat_1.fldist, result_flduration2);
            printf("время полета: %02.f ч %02.f мин %02.f сек\nНа %.f м 1° изменения азимута\n", 
                    result_flduration2[0], result_flduration2[1], result_flduration2[2], result_cl2sl2[3]);
            nav_time(result_flduration2[0], result_flduration2[1], result_flduration2[2]);
            return 0;
        case 2:
            printf("\n   Введи координаты гг.гггггг широты первой точки: ");
            if(scanf("%lf", &lat_1.lat) != 1) {
                printf("\nIncorect Input!\n");
                return 0;
            }
            printf("   Введи координаты ггг.гггггг долготы первой точки: ");
            if(scanf("%lf", &lng_1.lng) != 1) {
                printf("\nIncorect Input!\n");
                return 0;
            }
            printf("   Введи дальность до второй точки в м: ");
            if(scanf("%f", &lat_1.fldist) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи истинный курс на вторую точку в °: ");
            if(scanf("%lf", &maneuver.path_angle) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи приборную скорость самолета в км/ч: ");
            if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи направление ветра в °: ");
            if(scanf("%lf", &maneuver.wind_dir) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи скорость ветра в м/с: ");
            if(scanf("%lf", &maneuver.wind_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("\nПервая точка:   lat   %.6f°\n                lng   %.6f°\n", lat_1.lat, lng_1.lng);
            calcpoint_coord(lat_1.lat, lng_1.lng, maneuver.path_angle, lat_1.fldist, result_cl2sl2);
            printf("Вторая точка:   lat   %.6f°\n                lng   %.6f°\n\nКонечный азимут = %.6f°\n", result_cl2sl2[0], result_cl2sl2[1], result_cl2sl2[2]);
            calc_angle(maneuver.aircr_speed, maneuver.wind_speed, maneuver.path_angle, maneuver.wind_dir);
            calc_flduration(maneuver.ground_speed, lat_1.fldist, result_flduration2);
            printf("время полета: %02.f ч %02.f мин %02.f сек\nНа %.f м 1° изменения азимута\n", 
                    result_flduration2[0], result_flduration2[1], result_flduration2[2], result_cl2sl2[3]);
            nav_time(result_flduration2[0], result_flduration2[1], result_flduration2[2]);
            return 0;
        case 3:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 4:
        printf("\n   1. Преобразование координат из гг мм сс.мс в градусы\n"
                 "   2. Преобразование координат из градусов в гг мм сс.мс\n"
                 "   3. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! Input is out of range list!!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nПреобразование координат из гг мм сс.мс в градусы\n");
            printf("\n   Введи через пробел координаты WGS-84 широты: ");
            res = scanf("%d %d %f", &lat_1.deg, &lat_1.min, &lat_1.sec);
            if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, res) != 0)
                return 0;
            printf("   Введи через пробел координаты WGS-84 долготы: ");
            res = scanf("%d %d %f", &lng_1.deg, &lng_1.min, &lng_1.sec);
            if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, res) != 0)
                return 0;
            coord_transfer_wgs84(lat_1.deg, lat_1.min, lat_1.sec, res_lat1, res_lng1, res_lat2, res_lng2);
            printf("\nlat  %.6f°\nlng  %.6f°\n", res_lat1[0], res_lng1[0]);
            return 0;
        case 2:
            printf("\nПреобразование координат из градусов в гг мм сс.мс\n");
            printf("\n   Введи координаты широты: ");
            if(scanf("%lf", &lat_1.lat) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }    
            printf("   Введи координаты долготы: ");
            if(scanf("%lf", &lng_1.lng) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            } 
            coord_transfer_deg(lat_1.lat, lat_res1, lat_res2);
            coord_transfer_deg(lng_1.lng, lng_res1, lng_res2);

            if(lat_res1[0] < 0 && lng_res1[0] < 0) {
                printf("\nlat  %03.f° %02.f' %05.2f''\nlng %04.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
            if(lat_res1[0] < 0) {
                printf("\nlat  %03.f° %02.f' %05.2f''\nlng  %03.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
            if(lng_res1[0] < 0) {
                printf("\nlat   %02.f° %02.f' %05.2f''\nlng %04.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            } else
            printf("\nlat  %02.f° %02.f' %05.2f''\nlng %03.f° %02.f' %05.2f''\n", 
                    lat_res1[0], lat_res1[1], lat_res2[0], lng_res1[0], lng_res1[1], lng_res2[0]);
            return 0;
        case 3:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 5:
        printf("\n   1. Расчет радиуса, времени и длинны дуги разворота\n"
                 "   2. Расчет угла сноса и путевой скорости\n"
                 "   3. Расчет минимального расстояния для возможного погашения опоздания или избытка времени\n"
                 "   4. Расчет поправки в курс по боковому уклонению\n"
                 "   5. Расчет времени встречи и догона самолетов\n"
                 "   6. Пересчет скоростей и высот полета\n"
                 "   7. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! Input is out of range list!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nРасчет радиуса, времени и длинны дуги угла разворота\n");
            printf("\n   Введи скорость самолета в км/ч: ");
            if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи угол разворота в °: ");
            if(scanf("%lf", &maneuver.turn_angle) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи крен самолета в °: ");
            if(scanf("%lf", &maneuver.turn_roll) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            calc_turn(maneuver.aircr_speed, maneuver.turn_angle, maneuver.turn_roll, result_turn);
            printf("\nрадиус разворота = %.1f м\nвремя разворота = %.f мин %.f сек\nугловая скорость р-та = %.1f °/сек\nny = %.1f ед\nдлина дуги УР = %.1f м\nЛУР = %.1f м\n", 
                    result_turn[0], result_turn[1], result_turn[2], result_turn[3], result_turn[4], result_turn[5], result_turn[6]);
            return 0;
        case 2:
            printf("\nРасчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи скорость самолета в км/ч: ");
            if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи скорость ветра в м/с: ");
            if(scanf("%lf", &maneuver.wind_speed) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи курс полета самолета в °: ");
            if(scanf("%lf", &maneuver.path_angle) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            printf("   Введи направление навигационного ветера в °: ");
            if(scanf("%lf", &maneuver.wind_dir) != 1) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            calc_angle(maneuver.aircr_speed, maneuver.wind_speed, maneuver.path_angle, maneuver.wind_dir);
            return 0;
        case 3:
            calc_timecorrection(maneuver.aircr_speed, maneuver.max_aircr_speed, maneuver.time_range, res_timecorr);
            printf("\nпри избытке скорости = %.f км/ч\n", res_timecorr[0]);
            printf("минимальное расстояние до РТ = %.1f км\n", res_timecorr[1]);
            return 0;
        case 4:
            calc_trackcorrection(maneuver.lateral_line, maneuver.flight_track, maneuver.flcurr_range, res_trackcorr);
            printf("\nУС = %.1f°\nдополнительная ПК = %.1f°\nполная ПК = %.1f°\n", 
                    res_trackcorr[0], res_trackcorr[1], res_trackcorr[2]);
            return 0;
        case 5:
            printf("\n      1. Расчет времени встречи самолетов\n"
                     "      2. Расчет времени догона самолетов\n"
                     "      3. Выход\n");
            printf("         Выбери действие: ");
            if(scanf("%d", &item) != 1) {
                printf("\nError! Input is out of range list!\n");
                return 0;
            }
            switch(item) {
            case 1:
                printf("\n   Введи скорость первого самодета в км/ч: ");
                if(scanf("%lf", &maneuver.aircr_speed1) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                printf("   Введи скорость второго самодета в км/ч: ");
                if(scanf("%lf", &maneuver.aircr_speed2) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                printf("   Введи текущую дистанцию между самолетами в км: ");
                if(scanf("%lf", &maneuver.distance) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                calc_time_collision(maneuver.aircr_speed1, maneuver.aircr_speed2, maneuver.distance, result_coll);
                printf("\nвремя до столкновения = %.1f сек\n", result_coll[0]);
                return 0;
            case 2:
                printf("\n   Введи скорость первого самодета в км/ч: ");
                if(scanf("%lf", &maneuver.aircr_speed1) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                printf("   Введи скорость второго самодета в км/ч: ");
                if(scanf("%lf", &maneuver.aircr_speed2) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                 printf("   Введи текущую дистанцию между самолетами в км: ");
                if(scanf("%lf", &maneuver.distance) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }              
                calc_time_catch(maneuver.aircr_speed1, maneuver.aircr_speed2, maneuver.distance, result_catch);
                if(result_catch[0] == 0) {
                    printf("\nнет сближения, скорости равны\n");
                    return 0;
                }
                if(result_catch[0] < 0) {
                    printf("\nотставание на %.f км/ч\n", result_catch[0]);
                    return 0;
                } else
                    printf("\nвремя до столкновения %.1f сек\n", result_catch[1]);
                    return 0;
            case 3:
                printf("\nEnd of program\n");
                return 0;
            default:
                printf("\nIncorrect input!\n");
                return 0;
            }
        case 6:
            printf("\n      1. Пересчет скоростей полета\n"
                     "      2. Пересчет высот полета\n"
                     "      3. Выход\n");
            printf("         Выбери действие: ");
            if(scanf("%d", &item) != 1) {
                printf("\nError! Input is out of range list!\n");
                return 0;
            }
            switch(item) {
            case 1:
                printf("\n         1. Пересчет скоростей из км/ч в узлы\n"
                         "         2. Пересчет скоростей из узлов в км/ч\n"
                         "         3. Пересчет приборной скорости в истинную воздушную\n"
                         "         4. Выход\n");
                printf("            Выбери действие: ");
                if(scanf("%d", &item) != 1) {
                    printf("\nError! Input is out of range list!\n");
                    return 0;
                }
                switch(item) {
                case 1:
                    printf("\n   Введи скорость в км/ч: ");
                    if(scanf("%lf", &flight.ias) != 1) {
                        printf("\nIncorrect printf!\n");
                        return 0;
                    }
                    kmh_to_knh(flight.ias, result_knh);
                    printf("\nскорость %.f км/ч = %.f узлов\n", flight.ias, result_knh[0]);
                    return 0;
                case 2:
                    printf("\n   Введи скорость в узлах: ");
                    if(scanf("%lf", &flight.ias) != 1) {
                        printf("\nIncorrect input!\n");
                        return 0;
                    }
                    knh_to_kmh(flight.ias, result_kmh);
                    printf("\nскорость %.f узлов = %.f км/ч\n", flight.ias, result_kmh[0]);
                    return 0;
                case 3:
                    printf("\n   Введи скорость приборную в км/ч: ");
                    if(scanf("%lf", &flight.ias) != 1) {
                        printf("\nIncorrect input!\n");
                        return 0;
                    }
                    printf("   Введи высоту полета в метрах: ");
                    if(scanf("%lf", &flight.alt) != 1) {
                        printf("\nIncorrect input!\n");
                        return 0;
                    }
                    printf("   Введи температуру у земли в °C: ");
                    if(scanf("%lf", &flight.airtemp_h) != 1) {
                        printf("\nIncorrect input!\n");
                        return 0;
                    }
                    ias_to_tas(flight.ias, flight.alt, flight.airtemp_h, result_tas);
                    printf("\nистинная скорость = %.f км/ч\n", result_tas[0]);
                    return 0;
                case 4:
                    printf("\nEnd of program\n");
                    return 0;
                default:
                    printf("\nIncorrect input!\n");
                    return 0;
                }
            case 2:
                printf("\n         1. Пересчет высоты из метров в футы\n"
                         "         2. Пересчет высоты из футов в метры\n"
                         "         3. Выход\n");
                printf("            Выбери действие: ");
                if(scanf("%d", &item) != 1) {
                    printf("\nError! Input is out of range list!\n");
                    return 0;
                }
                switch(item) {
                case 1:
                    printf("\n   Введи высоту приборную в м: ");
                        if(scanf("%lf", &flight.alt) != 1) {
                            printf("\nIncorrect input!\n");
                            return 0;
                        }
                    hm_to_hph(flight.alt, result_hph);
                        printf("\nвысота = %.f футов\n", result_hph[0]);
                        return 0;
                case 2:
                    printf("\n   Введи высоту приборную в футах: ");
                        if(scanf("%lf", &flight.alt) != 1) {
                            printf("\nIncorrect input!\n");
                            return 0;
                        }
                    hph_to_hm(flight.ias, result_hm);
                        printf("\nвысота = %.f метров\n", result_hm[0]);
                        return 0;
                case 3:
                    printf("\nEnd of program\n");
                    return 0;
                default:
                    printf("\nIncorrect input!\n");
                    return 0;
                }                                                         
            case 3:
                printf("\nEnd of program\n");
                return 0;
            default:
                printf("\nIncorrect input!\n");
                return 0;
            }                
        case 7:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 6:
        printf("\nEnd of program\n");
        return 0;
    default:
        printf("\nIncorrect input!\n");
        return 0;
    }
    return 0;
}

/*
    scanf("Потребн длина ВПП при взлете, м: ", &req_rwaylen_TO);
    scanf("Потребн длина ВПП при посадке, м: ", &req_rwaylen_land);
    scanf("Прак потолок, м: ", &prac_flceil);
*/