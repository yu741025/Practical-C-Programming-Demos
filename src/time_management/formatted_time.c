/*This implementation retrieves the current time in the Taipei time zone, formats it into a human-readable string, and prints it to the console.
 * 1. Include necessary header files:
 *    - stdio.h: Provides basic input/output functionality.
 *    - stdlib.h: Provides functions such as setenv and tzset.
 *    - time.h: Provides time-related functionality, such as time, localtime, and strftime.
 */

/*
 * 2. Set the time zone:
 *    - Use the setenv function to set the "TZ" environment variable to "Asia/Taipei". 
 *      This ensures that subsequent time operations are based on the Taipei time zone.
 *    - Call the tzset function to apply the time zone settings.
 */

/*
 * 3. Retrieve the current time:
 *    - Use the time function to get the current time (represented as the number of seconds
 *      since January 1, 1970, 00:00:00 UTC) and store it in the raw_time variable.
 *    - Use the localtime function to convert raw_time into a structure containing
 *      detailed local time information, and store this in the time_info structure.
 */

/*
 * 4. Format the time information:
 *    - Use the strftime function to format the time_info structure's data into a 
 *      human-readable string format, and store it in the time_buffer variable.
 *    - The specified format includes: abbreviated weekday name, month, day, hour:minute:second,
 *      time zone, and year.
 */

/*
 * 5. Output the formatted time:
 *    - Use the printf function to display the formatted time string stored in time_buffer 
 *      to the standard output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  time_t raw_time;
  struct tm *time_info;
  char time_buffer[128];

  setenv("TZ", "Asia/Taipei", 1);
  tzset();

  time(&raw_time);
  time_info = localtime(&raw_time);

  strftime(time_buffer, 128, "%a %b %d %H:%M:%S %Z %Y", time_info);
  printf("%s\n", time_buffer);
}