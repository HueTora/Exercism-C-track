#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>


unsigned int sum_of_digits(unsigned int number);
bool luhn(const char *num);

#endif
