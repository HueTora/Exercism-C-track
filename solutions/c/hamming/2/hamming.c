#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (strlen(rhs) == strlen(lhs)){    
        unsigned int hamming_dist = 0;
        for (; *rhs && *lhs; lhs++, rhs++){
            if(*rhs != *lhs) hamming_dist++;
        }
        return hamming_dist;
    } 
    else return -1;
}