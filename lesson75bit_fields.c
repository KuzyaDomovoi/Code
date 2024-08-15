#include <stdio.h>

// bit fields is used for compact datapresentation;

struct date_time {
    unsigned int day : 5; // 5 bit
    unsigned mounth : 4;
    unsigned year : 12;
    unsigned hour : 5;
    unsigned min : 6;
    unsigned sec : 6;
};

// 5 + 4 + 12 + 6 + 6 + 5 = 32 + 6 (bit) => 4 + 4 = 8 (byte);

int main(void)
{
    struct date_time dt;
    struct date_time dtime = {14, 10, 2023, 14, 43, 18};
    char week[] = "sat";

    printf("%ld\n", sizeof(dtime));
    printf("%s %02d/%02d/%d %02d:%02d:%02d\n", 
        week, dtime.day, dtime.mounth, dtime.year, dtime.hour, dtime.min, dtime.sec);

    return 0;
}
