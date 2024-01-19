#include <stdio.h>

int main(void)
{
    FILE* f = popen("termux-location", "r");
    if(!f) return !0;                          
    char buf[1024] = {0};
    fread(buf, sizeof(buf), 1, f);
    
    FILE* fp = fopen("gpsd.txt", "w");
    if(!fp) return !0;
    fputs(buf, fp);
    fclose(fp);

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
