#include "space_age.h"


float proportion[8] = {0.2408467f, 0.61519726f, 1.0f, 1.8808158f, 11.862615f, 29.447498f, 84.016846f, 164.79132f};

float age(planet_t planet, int64_t seconds) {

    if ((int) planet > -1) return (float) (seconds/(31557600 * proportion[(int)planet]));
    else return -1;
    
    
}