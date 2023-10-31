#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int wind_angle, magnetpath_angle, aircr_speed, wind_dir, graund_speed, wind_speed, drift_angle; 
    double t;

    printf("\n Расчет угла сноса и путевой скорости по известному вектору ветра\n");
    printf("\n   Введи через пробел значение V полета с-та в км/ч, U ветра в м/с, НВ° и МПУ°: ");
    while(scanf("%d %d %d %d", &aircr_speed, &wind_speed, &wind_dir, &magnetpath_angle) != 4) {
        printf("\nError_input!\n");
        return 0;
    }
    if(wind_dir < magnetpath_angle)
        wind_angle = 360 - wind_dir - magnetpath_angle;
    else
        wind_angle = wind_dir - magnetpath_angle;    
    if(wind_angle >= 181) {
        t = (double)wind_speed / aircr_speed * sin((wind_angle - 180) * 3.14 / 180.0);
        drift_angle = rint(asin(t) * 180.0 / 3.14);
        graund_speed = sin((wind_angle + drift_angle) * 3.14 / 180.0) / sin(wind_angle * 3.14 / 180.0) * aircr_speed;
    } else
        t = (double)wind_speed / aircr_speed * sin(wind_angle);
        drift_angle = rint(asin(t) * 180.0 / 3.14);
        graund_speed = sin((wind_angle + drift_angle) * 3.14 / 180.0) / sin(wind_angle * 3.14 / 180.0) * aircr_speed;
    printf("   (double)wind_speed / aircr_speed = %.2f\n", (double)wind_speed / aircr_speed);
    printf("   sin((wind_angle - 180) * 3.14 / 180) = %.2f\n", sin((wind_angle - 180) * 3.14 / 180.0));
    printf("   t = %.2f\n", t);
    printf("\n   wind_angel = %d\n", wind_angle);
    printf("\n   при скорости полета с-та %d км/ч, скорости ветра %d км/ч, направлении ветра %d° и МПУ %d°\n   угол сноса = %d°\n   путевая скорость = %d км/ч\n",
            aircr_speed, wind_speed, wind_dir, magnetpath_angle, drift_angle, graund_speed);

    return 0;     
}
