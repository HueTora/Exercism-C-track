#include "armstrong_numbers.h"
#include <stddef.h>
#include <math.h>

bool is_armstrong_number(int candidate) {

    int div_number = candidate;
    size_t numbers_tot = 0;
    // Counts number of digits
    while (div_number > 0) {
        div_number /= 10; 
        numbers_tot++;
    }
    
    int sus_armstrong = 0;
    int current_number = 0;
    
    for (size_t i = 0; i < numbers_tot; i++) {
        // Get number by number
        current_number = (candidate % (int) pow(10, i+1)) / pow(10, i);
        sus_armstrong += pow(current_number, numbers_tot);
    }
    
    return sus_armstrong == candidate;
}