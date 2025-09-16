#include "allergies.h"
#include <stdbool.h>
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, unsigned int score) {
    // Allergic - if place of bit (allergy) that corresponds to the power of 2 is set
    return (1 & (score >> allergen));
}

allergen_list_t get_allergens(unsigned int score) {
    allergen_list_t list = {0, {0,0,0,0,0,0,0,0}};
    
    for (int i = ALLERGEN_EGGS; i < ALLERGEN_COUNT; i++) {
        if (is_allergic_to(i, score)) {
            list.allergens[i] = true;
            list.count++;
        }  
    }
    return list;
}