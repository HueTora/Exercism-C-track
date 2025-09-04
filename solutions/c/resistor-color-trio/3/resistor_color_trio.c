#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>

resistor_value_t color_code(resistor_band_t bands[]) {
    
    // Calculate value without prefix 
    uint16_t value_digits = bands[1] * ((uint16_t) pow(10, (bands[2]) % 3)) + bands[0] * ((uint16_t) pow(10, (bands[2] + 1) % 3));
    // Calculate prefix
    uint16_t value_of_prefix = log10((bands[0] * 10 + bands[1]) * ( (long int) pow(10, bands[2]) ) ) / 3;

    resistor_value_t resistor = {value_digits, value_of_prefix};
    
    return resistor;  
}