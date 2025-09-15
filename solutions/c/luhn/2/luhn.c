#include "luhn.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define WHITESPACE 32

unsigned int sum_of_digits(unsigned int number) {
    return (number < 10) ? number : ((number == 10) ? 1 : 1 + (number % 10));
}


bool luhn(const char *num) {

    char character;
    size_t number_counter = 0;
    unsigned int number;
    size_t char_counter = strlen(num);
    num += char_counter;
    unsigned int sum = 0;
    
    for(; char_counter; char_counter--) {
        num--;
        character = *num;
        
        // Ignore if character is a whitespace 
        if (character == WHITESPACE) continue;
        
        // False if ASCII code is not a number 
        if (character >= 48 && character <= 57){
            number = character - 48;
            number_counter++;
        } 
        else return false;
        
        // Calculate sum of numbers per algorithm
        if (!(number_counter % 2)) sum += sum_of_digits(2 * number);
        else sum += number;
    }

    return (number_counter > 1 && sum % 10 == 0) ? true : false;
}
