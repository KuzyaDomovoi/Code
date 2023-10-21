#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t rawtime, then, now;
    struct tm* timeinfo;
    int year, month, day, hour, minute, seconds;
    int dif;
 
    printf("Enter year: "); scanf("%d", &year);
    printf("Enter month (number): "); scanf("%d", &month);
    printf("Enter day: ");scanf("%d", &day);
    printf("Enter hour: "); scanf("%d", &hour);
    printf("Enter minutes: "); scanf("%d", &minute); 
    printf("Enter seconds: "); scanf("%d", &seconds);
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = seconds;

    time(&now);
    then = mktime(timeinfo);
    dif = difftime(now, rawtime) + difftime(rawtime, then); // in seconds;
    printf("\n%d seconds have passed by since.\n",dif);

    dif = dif / 60; // in minutes;
    printf("\n%d minutes have passed by since.\n",dif);

    dif = dif / 60; // in hours;
    printf("\n%d hours have passed by since.\n",dif);   
    
    dif = dif / 24; // in days;
    printf("\n%d days have passed by since.\n",dif);

    dif = dif / 30; // in months;
    printf("\n%d months have passed by since.\n",dif);

    getchar();

    return 0;
}
