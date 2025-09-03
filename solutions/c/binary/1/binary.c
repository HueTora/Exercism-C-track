#include "binary.h"
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int convert(const char *input) {

    int power = 0;
    int result = 0;
    size_t length = 0;
    while (*input != '\0') {
        length++;
        input++;
    }
    
    input -= length;
    
    while (*input != '\0') {
        if (*input == '1') result += pow(2, (length - 1) - power);
        else if (*input != '0') return -1; 

        power++;
        input++;
    }

    
        return result;
    }