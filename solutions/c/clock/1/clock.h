#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

#define MAX_STR_LEN sizeof("##:##")

typedef struct {
   char text[MAX_STR_LEN];
} clock_t;


clock_t clock_create(int hour, int minute);
void write_to_clock(clock_t *cptr, int hour, int minute);
clock_t clock_add(clock_t clock, int minute_add);
clock_t clock_subtract(clock_t clock, int minute_subtract);
bool clock_is_equal(clock_t a, clock_t b);
int *calc_time(int hour, int minute);
int *read_time(clock_t * cptr);
#endif
