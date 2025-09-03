#include <stdint.h>
#ifndef DARTS_H
#define DARTS_H


typedef struct {
    float x;
    float y;
} coordinate_t;

enum points {
    OUTSIDE_TARGET = 0,
    OUTER_CIRCLE = 1,
    MIDDLE_CIRCLE = 5,
    INNER_CIRCLE = 10
};

uint8_t score(coordinate_t landing_pos);

uint8_t power(int number);

#endif
