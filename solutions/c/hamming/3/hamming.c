#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (strlen(rhs) == strlen(lhs)){    
        unsigned int hamming_dist = 0;
        for (; *rhs && *lhs; lhs++, rhs++){
            hamming_dist += *rhs != *lhs;
        }
        return hamming_dist;
    } 
    else return -1;
}