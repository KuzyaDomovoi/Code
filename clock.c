#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

  int hour = tm.tm_hour;
  int minute = tm.tm_min;
  int second = tm.tm_sec;
  
  while (1) {

    // Print the time in HH : MM : SS format
    printf("%02d : %02d : %02d \r", hour, minute, second);

    // Clear the output buffer in gcc
    fflush(stdout);

    // Increment second
    second++;

    // Update hour, minute and second
    if (second == 60) {
      minute += 1;
      second = 0;
    }

    if (minute == 60) {
      hour += 1;
      minute = 0;
    }

    if (hour == 24) {
      hour = 0;
      minute = 0;
      second = 0;
    }

    // Wait for 1 second
    sleep(1);
  }
  return 0;
}
