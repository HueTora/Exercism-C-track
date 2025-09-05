#include "gigasecond.h"
#include <time.h>


void gigasecond(time_t input, char *output, size_t size) {

    time_t date_after = input + 1000000000;
    struct tm* ptime = gmtime(&date_after);

    strftime(output, size, "%Y-%m-%d %X", ptime);    
}