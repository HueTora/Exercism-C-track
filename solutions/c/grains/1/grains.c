#include "grains.h"
#include <math.h>



uint64_t square(uint8_t index) {
    if (index <= 0 || index > 64) return 0;
    if (index == 1) return 1;
    else return 2 * square(index-1);
}

uint64_t total(void) {
    uint64_t sum = 0;
    for (int i = 0; i <= 64; i++) {
        sum += square(i);
    }
    return sum;
}