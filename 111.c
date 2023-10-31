#include <stdio.h>
#include <math.h>

int main(void)
{
    int turn_time, turn_time_m, turn_time_s, turn_rad, turn_roll, turn_angle, wind_angle, 
    magnetpath_angle, aircr_speed, wind_dir, graund_speed, wind_speed, drift_angle;
           
    printf("\n Расчет угла сноса и путевой скорости по известному вектору ветра\n");
    printf("\n   Введи через пробел значение V полета с-та в км/ч, U ветра в м/с, НВ° и МПУ°: ");
    while(scanf("%d %d %d %d", &aircr_speed, &wind_speed, &wind_dir, &magnetpath_angle) != 4) {
        printf("\nError_input!\n");
        return 0;
    }
    drift_angle = rint(asin((float)wind_speed / aircr_speed * sin((wind_dir - magnetpath_angle) * 3.14 / 180)) / 3.14 * 180);
    graund_speed = sin((wind_dir - magnetpath_angle + drift_angle)* 3.14 / 180) / sin((wind_dir - magnetpath_angle) * 3.14 / 180) * aircr_speed;;
    printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении ветра %d° и МПУ %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n   ",
            aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);
            
    return 0;
}
