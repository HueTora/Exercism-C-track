#include "allergies.h"
#include <stdbool.h>
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, unsigned int score) {
    allergen_list_t list = get_allergens(score);
    return list.allergens[allergen];
}

allergen_list_t get_allergens(unsigned int score) {
    allergen_list_t list = {0, {0,0,0,0,0,0,0,0}};
    
    for (int i =0; i < 8; i++) {
        // Allergic - if place of bit (allergy) that corresponds to the power of 2 is set
        if (1 & (score >> i)) {
            list.allergens[i] = true;
            list.count++;
        }  
    }
    return list;
}