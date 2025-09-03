#include "raindrops.h"
#include <stdio.h>

void convert(char result[], int drops) {


    char str[16];
    sprintf(str, "%d", drops);
        
    snprintf(result, 16, "%s%s%s", (drops % 3 == 0) ? "Pling" : "\0",
                                   (drops % 5 == 0) ? "Plang": "\0",
                                   (drops % 7 == 0) ? "Plong" : ((drops % 3 == 0 || drops % 5 == 0 || drops % 7 == 0) ? "\0" : str)     
                                    );
}