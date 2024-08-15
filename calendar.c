#include <stdio.h>
#include <time.h>

static inline int get_RUSSIAN_wday(struct tm* tm)
{
    return(tm->tm_wday + 6) % 7;
}; //:%s/tm->tm_wday/get_RUSSIAN_wday(tm)/g

int main(void)
{   
    time_t now;
    struct tm* timeinfo;
    int year;
    char* month[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", 
                     "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    printf("Введи необходимый год: ");
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
                printf("\n\n  %s\n", month[timeinfo->tm_mon]);
                printf("  __________________________\n");
                printf("  Пн  Вт  Ср  Чт  Пт  Сб  Вс\n\n");
                for(int j = 0; j < (get_RUSSIAN_wday(timeinfo)); j++)
                    printf("    ");
                m++;
                break;
            }
            if(m == 11 && timeinfo->tm_mon == 0) { // "end of year";
                m++;
                break;
            }
            printf("%4d", timeinfo->tm_mday); // routine;
            
            if(get_RUSSIAN_wday(timeinfo) == 6) // "end of week";
                printf("\n");
        }
    }
    getchar(); 
    getchar();
    
    return 0;
}
