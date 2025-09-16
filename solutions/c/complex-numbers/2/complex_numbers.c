#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{

    return (complex_t) { .real = a.real + b.real,
                         .imag = a.imag + b.imag };
}

complex_t c_sub(complex_t a, complex_t b)
{
    
    return (complex_t) { .real = a.real - b.real, 
                         .imag = a.imag - b.imag };
}

complex_t c_mul(complex_t a, complex_t b)
{

    return (complex_t) { .real = a.real * b.real - a.imag * b.imag , 
                         .imag = a.imag * b.real + a.real * b.imag };
}


complex_t c_div(complex_t a, complex_t b)
{
    double denominator = (b.real * b.real + b.imag * b.imag);
    return (complex_t) { .real = (a.real * b.real + a.imag * b.imag) / denominator, 
                         .imag = (a.imag * b.real - a.real * b.imag) / denominator };
}

double c_abs(complex_t x)
{
    return hypot(x.real, x.imag);
}

complex_t c_conjugate(complex_t x)
{
    x.imag *= -1;
    return x;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    return (complex_t) { .real = exp(x.real) * cos(x.imag), 
                         .imag = exp(x.real) * sin(x.imag) };
}
