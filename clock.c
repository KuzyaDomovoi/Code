#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d/%02d/%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

  int hours = tm.tm_hour;
  int minutes = tm.tm_min;
  int seconds = tm.tm_sec;
  
  while(1) {
      // Print the time in HH : MM : SS format
      printf("%02d : %02d : %02d \r", hours, minutes, seconds);
      // Clear the output buffer in gcc
      fflush(stdout);
      // Increment second
     seconds++;
      // Update hour, minute and second
     if(seconds == 60) {
        minutes += 1;
        seconds = 0;
      }
      if(minutes == 60) {
        hours += 1;
        minutes = 0;
      }
      if(hours == 24) {
        hours = 0;
        minutes = 0;
        seconds = 0;
      }
      // Wait for 1 second
      sleep(1);
  }
  return 0;
}
