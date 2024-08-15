#include<stdio.h>
 
int main()
{
    double d;
    FILE* fr = fopen("gpsd.txt", "r");
    if(!fr) return !0;
    while(!feof(fr)) {
    	if(fscanf(fr, "%*s%lf,", &d) == 1)
            printf("%lf\n", d);
    }
    fclose(fr);
    
    return 0;
}
