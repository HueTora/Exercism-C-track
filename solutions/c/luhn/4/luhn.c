#include "luhn.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

unsigned int sum_of_digits(unsigned int number) {
    return (number < 10) ? number : ((number == 10) ? 1 : 1 + (number % 10));
}


bool luhn(const char *num) {

    char character;
    size_t number_counter = 0;
    unsigned int number;
    unsigned int sum = 0;
    
    for(size_t i = strlen(num); i; i--) {

        character = num[i - 1];
        // Ignore if character is a whitespace 
        if (character == ' ') continue;
        
        // False if ASCII code is not a number 
        if (character >= '0' && character <= '9'){
            number = character - '0';
            number_counter++;
        } 
        else return false;
        
        // Calculate sum of numbers per algorithm
        if (!(number_counter % 2)) sum += sum_of_digits(2 * number);
        else sum += number;
    }

    return (number_counter > 1 && sum % 10 == 0) ? true : false;
}
