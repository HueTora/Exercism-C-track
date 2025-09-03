#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t landing_pos){
    
    double radius = sqrt(pow(landing_pos.x, 2) + pow(landing_pos.y, 2)); 
    if (radius <= 1) return INNER_CIRCLE;
    else if (radius <= 5) return MIDDLE_CIRCLE;
    else if (radius <= 10) return OUTER_CIRCLE;
    else return OUTSIDE_TARGET;
}
