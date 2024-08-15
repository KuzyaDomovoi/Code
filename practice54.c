#include <stdio.h>
#include <math.h>

double get_area_triangle(double length, double height)
{
    if(length <= 0 || height <= 0)
        return NAN;

    double triangle = (length * height) / 2.0;
    return triangle;
}

double get_area_rectangle(double length, double height)
{
    if(length <= 0 || height <= 0)
        return NAN;

    double rectangle = get_area_triangle(length, height) * 2.0;
    return rectangle;
}

int main(void)
{
    double l, h;

    printf("Input length: ");
    if(scanf("%lf", &l) != 1) {
        printf("Error input!");
        return 0;
    }
    printf("Input height: ");
    if(scanf("%lf", &h) != 1) {
        printf("Error input!");
        return 0;
    }
    printf("S_tri = %.2f\nS_rect = %.2f\n", get_area_triangle(l, h), get_area_rectangle(l, h));

    return 0;
}
