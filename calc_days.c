#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t rawtime, then, now;
    struct tm* timeinfo;
    int year, month, day, hour;
    int dif;
 
    printf("Enter year: "); 
    scanf("%d", &year);
    printf("Enter month (number): "); 
    scanf("%d", &month);
    printf("Enter day: "); 
    scanf("%d", &day);
    printf("Enter hour: "); 
    scanf("%d", &hour);
 
    time(&rawtime );
    timeinfo = localtime(&rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
 
    time(&now);
    then = mktime(timeinfo);
    dif = difftime(now, rawtime) + difftime(rawtime, then); // in seconds;
 
    dif = dif / 3600; // in hours;
    printf("\n %d hours have passed by since\n",dif);
 
    dif = dif / 24; // in days;
    printf("\n %d days have passed by since\n",dif);
 
    getchar();

    return 0;
}
