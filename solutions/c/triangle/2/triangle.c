#include "triangle.h"
#include <stdbool.h>
#include <math.h>
#include <float.h>


bool is_triangle(triangle_t sides) {
    
    float are_zeros = (sides.a * sides.b * sides.c);
    
    return (sides.a + sides.b - sides.c) >= FLT_EPSILON && 
           (sides.a + sides.c - sides.b) >= FLT_EPSILON &&
           (sides.b + sides.c - sides.a) >= FLT_EPSILON &&
            are_zeros;
}

bool is_isosceles(triangle_t sides) {
    
    return ((fabs(sides.a - sides.b) < FLT_EPSILON) ||
            (fabs(sides.b - sides.c) < FLT_EPSILON)  || 
            (fabs(sides.a - sides.c) < FLT_EPSILON)) && 
            is_triangle(sides);
}

bool is_equilateral(triangle_t sides) {
    
    return (fabs(sides.a - sides.b) < FLT_EPSILON) &&
           (fabs(sides.b - sides.c) < FLT_EPSILON) &&
           is_triangle(sides);
}

bool is_scalene(triangle_t sides) {
    
    return !is_isosceles(sides) && is_triangle(sides);
}