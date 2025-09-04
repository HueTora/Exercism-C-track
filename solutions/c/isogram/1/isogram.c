#include "isogram.h"
#include <ctype.h> 

bool is_isogram(const char phrase[]) {

    if (!phrase) return false;
    
    int bitmask = 0; 
    int check_bit = 0;
    char letter;
    
    while ((letter = *phrase) != '\0') {
        if (tolower(letter) >= 'a' && tolower(letter) <= 'z') {
            check_bit = 1 << (tolower(letter) - 'a');
            check_bit &= bitmask;
            // If bit is unchanged - change bit (first occur.), otherwise if set - not isogram
            if (!check_bit) bitmask |= 1 << (tolower(letter) - 'a');
            else return false;
        }     
        phrase++;     
    }
    
    return true;
}