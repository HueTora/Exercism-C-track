#include "triangle.h"
#include <stdbool.h>
#include <math.h>
#include <float.h>


bool is_triangle(triangle_t sides) {
    float are_zeros = (sides.a * sides.b * sides.c);
    
    return are_zeros && ((sides.a + sides.b - sides.c) >= FLT_EPSILON) && ((sides.a + sides.c - sides.b) >= FLT_EPSILON) && ((sides.b + sides.c - sides.a) >= FLT_EPSILON);
}

bool is_isosceles(triangle_t sides) {
    if(!is_triangle(sides)) return false;
    
    return (fabs(sides.a - sides.b) < FLT_EPSILON) || (fabs(sides.b - sides.c) < FLT_EPSILON) || fabs(sides.a - sides.c) < FLT_EPSILON;
}

bool is_equilateral(triangle_t sides) {
    if(!is_triangle(sides)) return false;
    
    return (fabs(sides.a - sides.b) < FLT_EPSILON) && (fabs(sides.b - sides.c) < FLT_EPSILON);
}

bool is_scalene(triangle_t sides) {
    if(!is_triangle(sides)) return false;
    
    return !is_isosceles(sides);
}