#include <stdio.h>

// bit fields is used for compact datapresentation;

struct date_time {
    unsigned int day : 5; // 5 bit
    unsigned mounth : 4;
    unsigned year : 12;
    unsigned sec : 6;
    unsigned min : 6;
    unsigned hour : 5;
};

// 8 + 5 + 4 + 12 + 6 + 6 + 5 = 32 + 14 (bit) => 4 + 4 = 8 (byte);

int main(void)
{
    struct date_time dt;
    struct date_time dtime = {3, 5, 2023, 11, 7, 10};
    char week[] = "sat";
    
    printf("%ld\n", sizeof(dtime));
    printf("%s %02d/%02d/%d %02d:%02d:%02d\n", 
        week, dtime.day, dtime.mounth, dtime.year, dtime.hour, dtime.min, dtime.sec);

    return 0;
}
