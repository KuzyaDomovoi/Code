#include <stdio.h>
#include <stdlib.h>

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

    char str[30];
    FILE* fr = fopen("gpsd.txt", "r");
    if(!fr) return !0;
    fgets(str, sizeof(str), fr);
    fgets(str, sizeof(str), fr);
    printf("%s", str);
    fgets(str, sizeof(str), fr);
    printf("%s", str);

    fclose(fr);

    return 0;
}
