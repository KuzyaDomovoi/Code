#include <stdio.h>

int main()
{
    double d;
    int size = 0;
    FILE* fr = fopen("gpsd.txt", "r");
    if(!fr) return !0;
    for(int i = 0; i < 17; i++) {
        if(fscanf(fr, "%*s%lf", &d) == 1)
            printf("%lf\n", d);
    }
    fclose(fr);

    return 0;
}
