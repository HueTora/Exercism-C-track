#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void convert(char result[], int drops) {

    static rain_drops sounds[] = { {3, "Pling"}, {5, "Plang"}, {7, "Plong"} };
    result[0] = '\0';
    
    for (int i = 0; i < 3; i++) {
        if (!(drops % sounds[i].div)) strcat(result, sounds[i].sound);
    }

    if (!(result[0])) sprintf(result, "%d", drops);
}