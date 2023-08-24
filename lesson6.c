#include <stdio.h>

int main(void)
{
unsigned int time = 4 * 3600 + 32 * 60 + 18;
//hours : minutes : seconds;

unsigned int sec = time % 60;
unsigned int min = (time / 60) % 60;
unsigned int hour = time / 3600;

printf("%02d:%02d:%02d\n", hour, min, sec);

return 0;
}
