#include "resistor_color_trio.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>

resistor_value_t color_code(resistor_band_t bands[]) {
    
    long int value_digits = bands[1] * ((uint16_t) pow(10, (bands[2]) % 3)) + bands[0] * ((uint16_t) pow(10, (bands[2] + 1) % 3));

    long int value_real = (bands[0] * 10 + bands[1]) * ((long int) pow(10, bands[2]));

    resistor_value_t resistor = {value_digits, (uint16_t) (log10(value_real) / 3)};
    return resistor;

    
}