#include "armstrong_numbers.h"
#include <stddef.h>
#include <stdio.h>
#include <math.h>

bool is_armstrong_number(int candidate) {

    int div_number = candidate;
    size_t numbers_tot = 0;

    while (div_number >= 10) {
        div_number /= 10; 
        numbers_tot++;
    }

    int sus_armstrong = 0;
    int current_number = 0;
    for (size_t i = 0; i <= numbers_tot; i++) {
        current_number = (candidate % (int) pow(10, i+1)) / pow(10, i);
        printf("%d: %d^%lu", current_number, current_number, numbers_tot);
        sus_armstrong += pow(current_number, numbers_tot + 1);
    }
    printf("\n%d == %d \n", sus_armstrong, candidate);

    return sus_armstrong == candidate;
}