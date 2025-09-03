#include "resistor_color.h"
#include <stddef.h>

int color_code(resistor_band_t color) {
    resistor_band_t value = color;
    return value;
}

resistor_band_t* colors() {
     static resistor_band_t types[] = {COLORS};
    return types;
}