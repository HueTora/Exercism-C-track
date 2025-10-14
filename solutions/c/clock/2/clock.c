#include "clock.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int *read_time(clock_t *cptr) {
    int *ptr = malloc(2 * sizeof(int));
    if (ptr == NULL) printf("Memmory allocation failed");

    ptr[0] = (cptr->text[0] - '0') * 10 + cptr->text[1] - '0';
    ptr[1] = (cptr->text[3] - '0') * 10 + cptr->text[4] - '0';

    return ptr;
}

int *calc_time(int hour, int minute) {
      int hour_tot;

    // Calculate time based on sign of minute
    if (minute < 0) {
        // Calculate collective num of hours
        hour_tot = hour + floor(((float)minute / MINUTES_IN_HOUR)); 
        minute = (MINUTES_IN_HOUR - ((minute * -1) % MINUTES_IN_HOUR)) % MINUTES_IN_HOUR;
    }
    else {
        hour_tot = hour + (minute / MINUTES_IN_HOUR); 
        minute %= 60;
    }

    if (hour_tot < 0) hour = (HOURS_IN_DAY - (hour_tot * -1) % HOURS_IN_DAY) % 24;
    else hour = hour_tot % HOURS_IN_DAY;

    int *ptr = malloc(2 * sizeof(int));
    if (ptr == NULL) printf("Memmory allocation failed");

    ptr[0] = hour;
    ptr[1] = minute;

    return ptr;
}

void write_to_clock(clock_t *cptr, int hour, int minute) {

    int *tptr = calc_time(hour, minute);
    hour = tptr[0];
    minute = tptr[1];
    free(tptr);
    
    cptr->text[0] = '0' + hour / 10;
    cptr->text[1] = hour % 10 + '0';
    cptr->text[2] = ':';
    cptr->text[3] = '0' + minute / 10;
    cptr->text[4] = '0' + minute % 10;
}

clock_t clock_create(int hour, int minute) {
    clock_t clock = {"00:00"};
  
    // Write time to clock
    write_to_clock(&clock, hour, minute);
    return clock;
}

    
clock_t clock_add(clock_t clock, int minute_add) {
    int *readptr = read_time(&clock);
    // 0 - hours, 1 - minutes
    int *calcptr = calc_time(readptr[0], readptr[1] + minute_add); 
    free(readptr);
    write_to_clock(&clock, calcptr[0], calcptr[1]);
    free(calcptr);
    return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    return clock_add(clock, minute_subtract * -1);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return strncmp(a.text, b.text, MAX_STR_LEN) == 0;
}
