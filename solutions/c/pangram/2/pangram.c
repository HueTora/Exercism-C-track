#include "pangram.h"
#include <ctype.h>
#include <math.h>

bool is_pangram(const char *sentence) {
    
    if (!sentence) return false;

    char character = *sentence; 
    int bitmask = 0;

    
    while ((character = *sentence) != '\0') {
        character = tolower(character);
        if (character >= 'a' && character <= 'z') bitmask |= 1 << (character - 'a');
        sentence++;
    }
    return bitmask == (1 << 26) - 1;
    
}