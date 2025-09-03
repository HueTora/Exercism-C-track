#include "pangram.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>

bool is_pangram(const char *sentence) {
    
    if (!sentence) return false;
    
    int ascii_table[26];
    int ascii_counter = 0;
    for (size_t i = 0; i < 26; i++) {
        ascii_table[i] = 1;
    }

    int position; 
    
    for (size_t i = 0; i < strlen(sentence); i++) {
        position = ((int) tolower(sentence[i])) - 97;

        if (position >= 0 && position <= 25 && ascii_table[position]) {
            ascii_counter++;
            ascii_table[position] = 0;  
        }
   }
    
    if (ascii_counter == 26) return true;
    else return false;
}