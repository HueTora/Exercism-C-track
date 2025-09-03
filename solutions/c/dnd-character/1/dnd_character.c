#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

int * bubble_sort(int *array, size_t size) {
    size_t count = 0;
    while(count != 3) {
        count = 0;
        for (size_t i = 1; i < size; i++) {
                if (array[i - 1] > array[i]){
                    array[i] = array[i] ^ array[i-1]; 
                    array[i-1] = array[i] ^ array[i-1]; 
                    array[i] = array[i] ^ array[i - 1]; 
                }
                else count++;
            }
    }
    return array;
}

int ability(void) {
    srand(time(NULL));
    int points[4];
    // generate numbers 
    for (int i = 0; i < 4; i++) {
        points[i] = rand() % 6 + 1;
    }
    bubble_sort(points, 4);
    
    return points[1] + points[2] + points[3];
}

int modifier(int score) {
    float modifier = ((score - 10.0f) / 2.0f);
    return floor(modifier);
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t character = {ability(), ability(), ability(), ability(), ability(), ability(), 10 + modifier(character.constitution)};
    
    return character;
}