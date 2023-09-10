#include <stdio.h>

int main(void)
{
unsigned int time = 4 * 3600 + 32 * 60 + 18; // hours : minutes : seconds - 4 h : 32 min : 18 sec;

unsigned int sec = time % 60;
unsigned int min = (time / 60) % 60;
unsigned int hour = time / 3600;

printf("%02d:%02d:%02d\n", hour, min, sec); // 04:32:18

return 0;
}
