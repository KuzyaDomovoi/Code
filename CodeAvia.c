#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846
#define G    9.8
#define K    0.0175
#define R_E  6378137
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

struct geo_lat {
    double lat; double deg_1;
    unsigned sec; unsigned msec;
    unsigned deg; unsigned min;
} lat_1;

struct geo_lng {
    double lng; double deg_1;
    unsigned sec; unsigned msec;
    unsigned deg; unsigned min;
} lng_1;

struct geo_lat lat_2;
struct geo_lng lng_2;

void coord_transfer_deg(double deg, int result[2], float result2[1]) {
    int dd = trunc(deg);
    int mm = trunc((deg - dd) * 60);
    float ss = ((deg - dd) * 60 - mm) * 60;

    result[0] = dd;
    result[1] = mm;
    result2[0] = ss;
}

void coord_transfer_wgs84(int deg, int min, int sec, int msec, float result[2]) {
    double lat = lat_1.deg + lat_1.min / 60.0 + lat_1.sec / 3600.0 + lat_1.msec / 3600.0 / 60.0;
    double lng = lng_1.deg + lng_1.min / 60.0 + lng_1.sec / 3600.0 + lng_1.msec / 3600.0 / 60.0;

    result[0] = lat;
    result[1] = lng;
}

void calcfldist_bear(double lat1, double lng1, double lat2, double lng2, double result[3]) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);
    double delta_lng = lng_2.lng - lng_1.lng;
    double cdelta_lng = cos(delta_lng);
    double sdelta_lng = sin(delta_lng);

    double y = sdelta_lng * cl2;
    double x = (cl1 * sl2) - (sl1 * cl2 * cdelta_lng);
    double angledeg_init = atan2(y, x) * DEG;
    double initial_bearing = ((int)angledeg_init + 360) % 360;
    double reverse_bearing = ((int)angledeg_init + 180) % 360;

    y = sqrt(pow(cl2 * sdelta_lng, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta_lng, 2));
    x = sl1 * sl2 + cl1 * cl2 * cdelta_lng;
    double anglerad_init = atan2(y, x);
    double flight_dist = anglerad_init * R_E;

    result[0] = flight_dist;
    result[1] = initial_bearing;
    result[2] = reverse_bearing;

}

struct flrange_flduration {
    double engthrust_val;
    int airbornspeed; int average_climspeed; int climtime; int cruisspeed;
    int descspeed; int desctime; int load_weight; int full_fusupp; int fucons_preTO;
    int fucons_TO; int fucons_desc; int fucons_final_land_taxi; int guarfusupp_unusfures;

    double midaverage_climspeed; double flrang_clim; double fucons_clim; double fucons_cruise;
    double req_engthrustcruise; double lifttodrag_ratio; double hourfucons; double spec_fuconsclim;
    double spec_fuconscruise; double rangcruise; double timecruise;
    int flrange; int flduration; int flduration_h; int flduration_m;  
    } flight;

struct fltime_flangle_flspeed {
    int turn_time; int turn_time_m; int turn_time_s; int turn_roll; int turn_angle;
    int max_aircr_speed; int wind_angle; int magnetpath_angle; int aircr_speed; int wind_dir;
    int graund_speed; int drift_angle; int wind_speed; int speed_range; int time_range;
    int lateral_line; int flcurr_range; int flrem_range; int flight_track; int heading_corr;
    double turn_rad; double t; double mindist_checkpoint; double range_turnlead;
    double course_correction_curr; double course_correction_rem; double course_correction;
} maneuver;

bool range(int x, int a, int y) {
    if(x <= a && a <= y)
        return true;
    return false;
}

bool range2(int x, int a, int y) {
    if(a < x || a > y)
        return true;
    return false;
}

bool input_verif_lat(int a, int b, int c, int d, int res) {
    if(res != 4) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-90, a, 90)) {
        printf("\nIncorrect input! Range of latitude is -90...90\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59)) {
        printf("\nIncorrect input! Range of min and sec is 0...59\n");
        return true;
    }
    if(range2(0, d, 99)) {
        printf("\nIncorrect input! Range of msec is 0...99\n");
        return true;
    }
    if(range2(-89, a, 89) && (b > 0 || c > 0 || d > 0)) {
        printf("\nIncorrect input! If the latitude has value -90 or 90, the values of min, sec and msec should be 00 only\n");
        return true;
    } else return false;
}

bool input_verif_lng(int a, int b, int c, int d, int res) {
    if(res != 4) {
        printf("\nIncorrect input! It should be entered 4 values!\n");
        return true;
    }
    if(range2(-180, a, 180)) {
        printf("\nIncorrect input! Range of latitude is -180...180\n");
        return true;
    }
    if(range2(0, b, 59) || range2(0, c, 59)) {
        printf("\nIncorrect input! Range of min and sec is 0...59\n");
        return true;
    }
    if(range2(0, d, 99)) {
        printf("\nIncorrect input! Range of msec is 0...99\n");
        return true;
    }
    if(range2(-179, a, 179) && (b > 0 || c > 0 || d > 0)) {
        printf("\nIncorrect input! If the longitude has value -180 or 180, the values of min, sec and msec should be 00 only\n");
        return true;
    } else return false;
}

int main(void)
{
    int item;
    int res = 0;

    printf("\n1. Расчет дальности и продолжительности полета\n"
             "2. Расчет расстояния между двумя точками по их координатам\n"
             "3. Преобразование координат из градусов в гг мм сс.мс\n"
             "4. Расчеты маневрирования\n"
             "5. Выход\n");
    printf("   Выбери расчет или выход: ");
    if(scanf("%d", &item) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(item) {
    case 1:
        printf("Расчет дальности и продолжительности полета\n");
        printf("\n  величина тяги для ТРДД при номинал ррд в наборе на средн выс, H: ");
        if(scanf("%lf", &flight.engthrust_val) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  аэродинамическое качество с-та: ");
        if(scanf("%lf", &flight.lifttodrag_ratio) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость отрыва, км/ч: ");
        if(scanf("%d", &flight.airbornspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скор набора выс, км/ч: ");
        if(scanf("%d", &flight.average_climspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время набора выс, сек: ");
        if(scanf("%d", &flight.climtime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  крейс скорость, км/ч: ");
        if(scanf("%d", &flight.cruisspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  скорость на снижении, км/ч: ");
        if(scanf("%d", &flight.descspeed) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  время снижения, сек: ");
        if(scanf("%d", &flight.desctime) != 1) {
            printf("\nError_input!\n");
            return 0;
        }       
        printf("  масса снаряж самолета, кг: ");
        if(scanf("%d", &flight.load_weight) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  макс заправка топл, кг: ");
        if(scanf("%d", &flight.full_fusupp) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  удельный расход топл в наборе, кг: ");
        if(scanf("%lf", &flight.spec_fuconsclim) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  удельный расход топл по мрш в гп, кг: ");
        if(scanf("%lf", &flight.spec_fuconscruise) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на прогрев, опроб двиг и руление, кг: ");
        if(scanf("%d", &flight.fucons_preTO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на взлете, кг: ");
        if(scanf("%d", &flight.fucons_TO) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на снижении, кг: ");
        if(scanf("%d", &flight.fucons_desc) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  расход топл на кругу, посадке и заруливании, кг: ");
        if(scanf("%d", &flight.fucons_final_land_taxi) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        printf("  невырабатываемый остаток топл, кг: ");
        if(scanf("%d", &flight.guarfusupp_unusfures) != 1) {
            printf("\nError_input!\n");
            return 0;
        }
        flight.midaverage_climspeed = 0.5 * (flight.airbornspeed + flight.average_climspeed);
        flight.flrang_clim = (flight.average_climspeed * 3.6) * ((flight.climtime / 3600) / 1000);
        flight.fucons_clim = (flight.spec_fuconsclim * flight.engthrust_val) * (flight.climtime / 3600 ); 
        flight.fucons_cruise = flight.full_fusupp - flight.fucons_preTO - flight.fucons_TO - flight.fucons_clim - flight.fucons_desc - flight.fucons_final_land_taxi - flight.guarfusupp_unusfures;
        flight.req_engthrustcruise = (flight.load_weight * G) / flight.lifttodrag_ratio;
        flight.hourfucons = (flight.spec_fuconscruise * flight.req_engthrustcruise) / flight.cruisspeed;
        flight.rangcruise = flight.fucons_cruise / flight.hourfucons;
        flight.timecruise = flight.rangcruise / flight.cruisspeed;
        flight.flrange = (flight.midaverage_climspeed * flight.climtime / 3600) + (flight.cruisspeed * flight.timecruise) + (flight.descspeed * flight.desctime / 3600);
        flight.flduration = flight.climtime + (flight.timecruise * 3600) + flight.desctime;
        flight.flduration_h = (int)flight.flduration / 3600;
        flight.flduration_m = (int)flight.flduration % 3600 / 60;
        printf("\nРасполагаемый запас топлива = %.f кг\n", flight.fucons_cruise);
        printf("Дальность полета = %d км\nПродолжительность полета = %d ч %02d мин\n", 
                flight.flrange, flight.flduration_h, flight.flduration_m);
        return 0;
    case 2:
        printf("\nРасчет расстояния между двумя точками по их координатам\n");
        printf("\n   Введи координаты гг мм сс.мс WGS-84 широты первой точки: ");
        res = scanf("%d %d %d.%d", &lat_1.deg, &lat_1.min, &lat_1.sec, &lat_1.msec);
        if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, res) != 0)
            return 0;
        printf("   Введи координаты ггг мм сс.мс WGS-84 долготы первой точки: ");
        res = scanf("%d %d %d.%d", &lng_1.deg, &lng_1.min, &lng_1.sec, &lng_1.msec);
        if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, lng_1.msec, res) !=0)
            return 0;
        printf("\n   Введи координаты гг мм сс.мс WGS-84 широты второй точки: ");
        res = scanf("%d %d %d.%d", &lat_2.deg, &lat_2.min, &lat_2.sec, &lat_2.msec);
        if(input_verif_lat(lat_2.deg, lat_2.min, lat_2.sec, lat_2.msec, res) != 0)
            return 0;
        printf("   Введи координаты ггг мм сс.мс WGS-84 долготы второй точки: ");
        res = scanf("%d %d %d.%d", &lng_2.deg, &lng_2.min, &lng_2.sec, &lng_2.msec);
        if(input_verif_lng(lng_2.deg, lng_2.min, lng_2.sec, lng_2.msec, res) != 0)
            return 0;
        double lat1 = lat_1.deg + lat_1.min / 60.0 + lat_1.sec / 3600.0 + lat_1.msec / 3600.0 / 60.0;
        double lng1 = lng_1.deg + lng_1.min / 60.0 + lng_1.sec / 3600.0 + lng_1.msec / 3600.0 / 60.0;
        double lat2 = lat_2.deg + lat_2.min / 60.0 + lat_2.sec / 3600.0 + lat_2.msec / 3600.0 / 60.0;
        double lng2 = lng_2.deg + lng_2.min / 60.0 + lng_2.sec / 3600.0 + lng_2.msec / 3600.0 / 60.0;
        double result[3];
        calcfldist_bear(lat1, lng1, lat2, lng2, result);
        printf("\nПервая точка: lat  %02d° %02d' %02d.%02d''\n              lng %03d° %02d' %02d.%02d''\n",
                lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, lng_1.deg, lng_1.min, lng_1.sec, lng_1.msec);
        printf("Вторая точка: lat  %02d° %02d' %02d.%02d''\n              lng %03d° %02d' %02d.%02d''\n",
                lat_2.deg, lat_2.min, lat_2.sec, lat_2.msec, lng_2.deg, lng_2.min, lng_2.sec, lng_2.msec);
        printf("\nРасстояние = %.f м\nНачальный азимут = %.1f°\nНачальный пеленг = %.1f°\n", result[0], result[1], result[2]);
        return 0;
    case 3:
        printf("\n   1. Преобразование координат из гг мм сс.мс в градусы\n"
                 "   2. Преобразование координат из градусов в гг мм сс.мс\n"
                 "   3. Выход\n");
        printf("      Выбери расчет или выход: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nПреобразование координат из гг мм сс.мс в градусы\n");
            printf("\n   Введи через пробел координаты WGS-84 широты: ");
            res = scanf("%d %d %d.%d", &lat_1.deg, &lat_1.min, &lat_1.sec, &lat_1.msec);
            if(input_verif_lat(lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, res) != 0)
                return 0;
            printf("   Введи через пробел координаты WGS-84 долготы: ");
            res = scanf("%d %d %d.%d", &lng_1.deg, &lng_1.min, &lng_1.sec, &lng_1.msec);
            if(input_verif_lng(lng_1.deg, lng_1.min, lng_1.sec, lng_1.msec, res) !=0)
                return 0;
            float result[2];
            coord_transfer_wgs84(lat_1.deg, lat_1.min, lat_1.sec, lat_1.msec, result);
            printf("\n   lat  %.6f°\n   lng  %.6f°\n", result[0], result[1]);
            return 0;
        case 2:
            printf("\nПреобразование координат из градусов в гг мм сс.мс\n");
            printf("\n   Введи координаты широты: ");
            if(scanf("%lf", &lat_1.deg_1) != 1) {
                printf("incorrect input!\n");
                return 0;
            }    
            printf("   Введи координаты долготы: ");
            if(scanf("%lf", &lng_1.deg_1) != 1) {
                printf("incorrect input!\n");
                return 0;
            } 
            int lat_res[2];
            float lat_res2[1];
            int lng_res[2];
            float lng_res2[1];
            coord_transfer_deg(lat_1.deg_1, lat_res, lat_res2);
            coord_transfer_deg(lng_1.deg_1, lng_res, lng_res2);
            printf("\n   lat  %02d° %02d' %02.2f''\n   lng %03d° %02d' %02.2f''\n", 
                    lat_res[0], lat_res[1], lat_res2[0], lng_res[0], lng_res[1], lng_res2[0]);
            return 0;
        case 3:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 4:
        printf("\n   1. Расчет радиуса, времени и длинны дуги угла разворота\n"
                 "   2. Расчет угла сноса и путевой скорости по известному вектору ветра\n"
                 "   3. Расчет минимального расстояния для возможного погашения опоздания или избытка времени\n"
                 "   4. Расчет поправки в курс по расстоянию и боковому уклонению\n"
                 "   5. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! input out of range list!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nРасчет радиуса, времени и длинны дуги угла разворота\n");
            printf("\n   Введи через пробел скорость с-та в км/ч, угол° и крен°: ");
            if(scanf("%d %d %d", &maneuver.aircr_speed, &maneuver.turn_angle, &maneuver.turn_roll) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500) {
                printf("\nError! Input the unreal speed for an aircraft or for the wind!\n");
                return 0;
            }
            if(maneuver.turn_roll > 83) {
                printf("\nError! The turn_roll can't be more than 83°!\n");
                return 0;
            }
            maneuver.turn_rad = pow(maneuver.aircr_speed / 3.6, 2) / (G * tan(maneuver.turn_roll * RAD));
            maneuver.range_turnlead = K * maneuver.turn_rad * maneuver.turn_angle;
            maneuver.turn_time = (2 * M_PI * maneuver.aircr_speed / 3.6) / (G * tan(maneuver.turn_roll * RAD)) * maneuver.turn_angle / 360;
            maneuver.turn_time_m = (maneuver.turn_time / 60) % 60;
            maneuver.turn_time_s = maneuver.turn_time % 60;

            printf("\n   радиус разворота = %.1f м\n   время разворота = %d мин %02d сек\n   длина дуги УР = %.1f м\n", 
                    maneuver.turn_rad, maneuver.turn_time_m, maneuver.turn_time_s, maneuver.range_turnlead);
            return 0;
        case 2:
            printf("\nРасчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи через пробел значение скорость с-та в км/ч, скорость ветра в км/ч, курс полета с-та° и направление нав ветера°: ");
            if(scanf("%d %d %d %d", &maneuver.aircr_speed, &maneuver.wind_speed, &maneuver.magnetpath_angle, &maneuver.wind_dir) != 4) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.aircr_speed < 0 || maneuver.aircr_speed > 1500 || maneuver.wind_speed < 0 || maneuver.wind_speed > 300) {
                printf("\nError! Input the unreal speed for an aircraft or for the wind!\n");
                return 0;
            }
            if(maneuver.magnetpath_angle < 0 || maneuver.magnetpath_angle > 360 || maneuver.wind_dir < 0 || maneuver.wind_dir > 360) {
                printf("\nError! Angle can't be less 0° or more than 360°\n");
                return 0;
            }
            if(maneuver.wind_dir == maneuver.magnetpath_angle) {
                maneuver.drift_angle = 0;
                maneuver.graund_speed = maneuver.aircr_speed + maneuver.wind_speed;
                printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.graund_speed);
                return 0;
            }
            if(maneuver.wind_dir < maneuver.magnetpath_angle) {
                maneuver.wind_angle = 360 + maneuver.wind_dir - maneuver.magnetpath_angle;
            } else
                maneuver.wind_angle = maneuver.wind_dir - maneuver.magnetpath_angle;
            if(maneuver.wind_angle == 180 || maneuver.wind_angle == 0 || maneuver.wind_angle == 360) {
                maneuver.drift_angle = 0;
                maneuver.graund_speed = maneuver.aircr_speed - maneuver.wind_speed;
                printf("\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.graund_speed);
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
            maneuver.graund_speed = maneuver.aircr_speed * cos(maneuver.drift_angle * RAD) + maneuver.wind_speed * cos(maneuver.wind_angle * RAD);
            maneuver.heading_corr = maneuver.magnetpath_angle - maneuver.drift_angle;
            printf("\n   угол сноса = %d°\n   курс с учетом УС = %d°\n   путевая скорость = %d км/ч\n", maneuver.drift_angle, maneuver.heading_corr, maneuver.graund_speed);
            return 0;
        case 3:
            printf("\nРасчет минимального расстояния для возможного погашения опоздания или избытка времени\n");
            printf("\n   Введи через пробел приб скорость полета в км/ч, макс приб скорость в км/ч, " 
                   "макс возможный избыток или недостаток времени в сек: ");
            if(scanf("%d %d %d", &maneuver.aircr_speed, &maneuver.max_aircr_speed, &maneuver.time_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            if(maneuver.max_aircr_speed < maneuver.aircr_speed) {
                printf("\nError_input! The max_aircr_speed can't be less than aircr_speed!\n");
                return 0; 
            }   
            maneuver.speed_range = maneuver.max_aircr_speed - maneuver.aircr_speed;
            maneuver.mindist_checkpoint = ((double)maneuver.aircr_speed * maneuver.max_aircr_speed / maneuver.speed_range * maneuver.time_range / 3600);
            printf("\n   при избытке скорости = %d км/ч\n", maneuver.speed_range);
            printf("   минимальное расстояние до РТ = %.1f км\n", maneuver.mindist_checkpoint);
            return 0;
        case 4:
            printf("\nРасчет поправки в курс по расстоянию и боковому уклонению\n");
            printf("\n   Введи через пробел линейное боковое уклонение в км, общее расстояние до РТ в км, пройденное/оставшееся расстояние до РТ в км: ");
            if(scanf("%d %d %d", &maneuver.lateral_line, &maneuver.flight_track, &maneuver.flcurr_range) != 3) {
                printf("\nError_input!\n");
                return 0;
            }
            maneuver.flrem_range = maneuver.flight_track - maneuver.flcurr_range;
            maneuver.course_correction_curr = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * DEG);
            maneuver.course_correction_rem = (atan((double)maneuver.lateral_line / maneuver.flrem_range) * DEG);
            maneuver.course_correction = (atan((double)maneuver.lateral_line / maneuver.flcurr_range) * DEG) + (atan((double)maneuver.lateral_line / maneuver.flrem_range) * DEG);
            printf("   при ЛБУ = %d км:\n      боковое уклонение = УС = %.f°\n      дополнительная ПК = %.f°\n      полная ПК = %.f°\n", 
                    maneuver.lateral_line, maneuver.course_correction_curr, maneuver.course_correction_rem, maneuver.course_correction);
            return 0;
        case 5:
            printf("\nEnd of program\n");
            return 0;
        default:
            printf("\nIncorrect input!\n");
            return 0;
        }
    case 5:
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