#include "collatz_conjecture.h"

int steps(int start) {

    int step;
    
    if (start <= 0) return ERROR_VALUE;
    
    for (step = 0; start != 1; step++) {
        start = (start % 2 == 0) ? (start / 2) : ((start * 3) + 1);
    }
    return step;

}
