#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h> 

#define COLORS BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
#define PREF OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS

typedef enum { COLORS } resistor_band_t;

typedef enum { PREF } prefix;

typedef struct {
    uint16_t value;
    prefix unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t bands[]);

#endif
