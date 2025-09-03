#include "eliuds_eggs.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int egg_count(int dec_number) {

    int count = 0;
    
    while (dec_number > 0) {
        if(1 & dec_number) count++;
        dec_number = dec_number >> 1;
    }
    return count;
}