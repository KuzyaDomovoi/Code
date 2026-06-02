#include <stdio.h>
#include <math.h>

int main(void)
{

    int aircr_speed, max_aircr_speed, drift_angle, wind_speed, speed_range, time_range;
    double mindist_checkpoint, a;

    max_aircr_speed = 950;
    aircr_speed = 700;
    time_range = 60;
        
    speed_range = max_aircr_speed - aircr_speed;
    mindist_checkpoint = (double)aircr_speed * max_aircr_speed / speed_range * time_range / 3600;
    printf("\n   при избытке скорости = %d км/ч\n", speed_range);
    printf("   минимальное расстояние до РТ = %.1f км\n", mindist_checkpoint);

    return 0;
}