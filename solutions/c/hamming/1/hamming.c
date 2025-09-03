#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (strlen(rhs) == strlen(lhs)){
        unsigned int len = strlen(rhs);     
        unsigned int hamming_dist = 0;
        for (unsigned int i=0; i<len; i++){
            if(rhs[i] != lhs[i]) hamming_dist++;
        }
        return hamming_dist;
    } 
    else return -1;
}