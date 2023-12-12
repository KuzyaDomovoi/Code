#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "calc_aviacode.h"

#define M_PI 3.14159265358979323846
#define G    9.8
#define K    0.0175
#define R_E  6371008.8
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI
#define KNH  1.852

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

struct flrange_flduration {
    double airbornspeed; double average_climspeed; double climtime; double cruisspeed; double average_climspeed_1000; 
    double descspeed; double desctime; double load_weight; double full_fusupp; double fucons_preTO; double climtime_1000;
    double fucons_TO; double fucons_desc; double fucons_final_land_taxi; double guarfusupp_unusfures; double engthrust_val;
    double midaverage_climspeed; double flrang_clim; double fucons_clim; double fucons_cruise; double midaverage_climspeed_1000; 
    double req_engthrustcruise; double lifttodrag_ratio; double hourfucons; double spec_fuconsclim; double spec_fuconscruise; 
    double rangcruise; double timecruise; double flrang_clim_1000; double flrange; 
    int flduration; int flduration_h; int flduration_m; int flduration_s;
} flight;

struct fltime_flangle_flspeed {
    double turn_roll; double turn_angle; double max_aircr_speed; double wind_angle; double path_angle; 
    double aircr_speed; double wind_dir; double ground_speed; double drift_angle; double wind_speed; 
    double speed_range; double time_range; double lateral_line; double flcurr_range; double flrem_range; 
    double flight_track; double heading_corr; double turn_rad; double t; double mindist_checkpoint;
    double range_turnlead; double ny; double course_correction_curr; double course_correction_rem; double distance;
    double course_correction; double turn_speed; double aircr_speed1; double aircr_speed2; double time_collision; double time_cathch;
    int hours; int minutes; int seconds; int turn_time; int turn_time_m; int turn_time_s; 
} maneuver;

int main(void)
{
    int item, res = 0;
    double lat1, lat2, lng1, lng2;
    double result_flrange[2], result_flduration[2];
    double result_flduration2[3];
    double result_turn[6];
    double res_lat1[1], res_lng1[1], res_lat2[1], res_lng2[1];
    double result_db[4];
    double result_cl2sl2[4];
    double result_knh[1], result_kmh[1];
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
        flrange_duration_calc(flight.desctime, flight.full_fusupp, flight.fucons_TO, flight.fucons_desc, flight.fucons_final_land_taxi, 
                              flight.guarfusupp_unusfures, flight.cruisspeed, flight.engthrust_val, flight.fucons_preTO, flight.descspeed,
                              flight.spec_fuconsclim, flight.average_climspeed, flight.airbornspeed, result_flrange, result_flduration);
        printf("\nРасполагаемый запас топлива = %.f кг\n", result_flrange[0]);
        printf("Дальность полета = %.1f км\nПродолжительность полета = %02.f ч %02.f мин\n", 
                result_flrange[1], result_flduration[0], result_flduration[1]);
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
            printf("   Введи скорость ветра в км/ч: ");
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
            printf("   Введи скорость ветра в км/ч: ");
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
                 "   6. Пересчет скоростей\n"
                 "   7. Выход\n");
        printf("      Выбери действие: ");
        if(scanf("%d", &item) != 1) {
            printf("\nError! Input is out of range list!\n");
            return 0;
        }
        switch(item) {
        case 1:
            printf("\nРасчет радиуса, времени и длинны дуги угла разворота\n");
            printf("\n   Введи последовательно:\nскорость с-та в км/ч\nугол°\nкрен°\n");
            if(scanf("%lf %lf %lf", &maneuver.aircr_speed, &maneuver.turn_angle, &maneuver.turn_roll) != 3) {
                printf("\nIncorrect input!\n");
                return 0;
            }
            calc_turn(maneuver.aircr_speed, maneuver.turn_angle, maneuver.turn_roll, result_turn);
            printf("\nрадиус разворота = %.1f м\nвремя разворота = %.f мин %.f сек\nугловая скорость р-та = %.1f °/сек\nny = %.1f ед\nдлина дуги УР = %.1f м\n", 
                    result_turn[0], result_turn[1], result_turn[2], result_turn[3], result_turn[4], result_turn[5]);
            return 0;
        case 2:
            printf("\nРасчет угла сноса и путевой скорости по известному вектору ветра\n");
            printf("\n   Введи последовательно:\nскорость с-та в км/ч\nскорость ветра в км/ч\nкурс полета с-та°\nнаправление нав ветера°\n");
            if(scanf("%lf %lf %lf %lf", &maneuver.aircr_speed, &maneuver.wind_speed, &maneuver.path_angle, &maneuver.wind_dir) != 4) {
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
            printf("\nбоковое уклонение = УС = %.1f°\nдополнительная ПК = %.1f°\nполная ПК = %.1f°\n", 
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
                printf("\n   Введи последовательно:\nскорости двух самодетов на встречных курсах в км/ч\nдистанцию в км\n");
                if(scanf("%lf %lf %lf", &maneuver.aircr_speed1, &maneuver.aircr_speed2, &maneuver.distance) != 3) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                calc_time_collision(maneuver.aircr_speed1, maneuver.aircr_speed2, maneuver.distance, result_coll);
                printf("\nвремя до столкновения = %.1f сек\n", result_coll[0]);
                return 0;
            case 2:
                printf("\n   Введи последовательно:\nскорости двух самодетов на догоне в км/ч\nдистанцию в км\n");
                if(scanf("%lf %lf %lf", &maneuver.aircr_speed1, &maneuver.aircr_speed2, &maneuver.distance) != 3) {
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
            printf("\n      1. Пересчет скоростей из км/ч в узлы\n"
                     "      2. Пересчет скоростей из  узлов в км/ч\n"
                     "      3. Выход\n");
            printf("         Выбери действие: ");
            if(scanf("%d", &item) != 1) {
                printf("\nError! Input is out of range list!\n");
                return 0;
            }
            switch(item) {
            case 1:
                printf("\n   Введи скорость в км/ч: ");
                if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                kmh_to_knh(maneuver.aircr_speed, result_knh);
                printf("\nскорость %.f км/ч = %.f узлов\n", maneuver.aircr_speed, result_knh[0]);
                return 0;
            case 2:
                printf("\n   Введи скорость в узлах: ");
                if(scanf("%lf", &maneuver.aircr_speed) != 1) {
                    printf("\nIncorrect input!\n");
                    return 0;
                }
                knh_to_kmh(maneuver.aircr_speed, result_kmh);
                printf("\nскорость %.f узлов = %.f км/ч\n", maneuver.aircr_speed, result_kmh[0]);
                return 0;
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
