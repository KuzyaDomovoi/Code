#include <stdio.h>
#include <time.h>
 
int main()
{   time_t now;
    struct tm* timeinfo;
    int year;
    char* month[] = {"January", "February", "March", "April", "May", "June", 
                     "July", "August", "September", "October", "November", "December"};
    printf("Input needed Year: ");
    scanf("%d", &year);
    time(&now); // get current timeinfo and modify it to the user's choice;
    timeinfo = localtime(&now);
    timeinfo->tm_year = year - 1900; // years numeration from 1900;
    timeinfo->tm_mon = 0;
 
    int m = -1;
    while(m < 12) { 
        for(int i = 1; i < 33; i++) { // year days with "overload";
            timeinfo->tm_mday = i;
            mktime(timeinfo); // call mktime: the whole timeinfo for the day will be set;
    
            if(timeinfo->tm_mon > m) { // "end month" and "overload" processing;
                printf("\n");
                printf("\n%28s\n", month[timeinfo->tm_mon]);
                printf("  Mo  Tu  We  Th  Fr  Sa  Su\n");
                printf("  __________________________\n");
                for(int j = 0; j < (timeinfo->tm_wday); j++)
                    printf("    ");
                m++;
                break;
            }
            if(m == 11 && timeinfo->tm_mon == 0) { // "end of year";
                m++;
                break;
            }
            printf("%4d", timeinfo->tm_mday); // routine;
            
            if(timeinfo->tm_wday == 6) // "end of week";
                printf("\n");
        }
    }
    getchar(); 
    getchar();
    
    return 0;
}
