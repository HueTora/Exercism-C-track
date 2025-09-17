#include "sum_of_multiples.h"
#include <stdio.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {

    unsigned sum = 0;
    for (size_t i = 1; i < limit; i++) {
        for (size_t factor = 0; factor < number_of_factors; factor++) {
            if (!factors[factor]) continue;
            // If 'i' is divisible by factor - it is his multiply
            if (!(i % factors[factor])) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}