#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {

    size_t length = strlen(dna);
    char *ptr_rna = malloc((length + 1) * sizeof(char));
    
    for(size_t i = 0; i <= length; i++) {
        switch(dna[i]) {
            case 'G':
                ptr_rna[i] = 'C';
                break;
            case 'C': 
                ptr_rna[i] = 'G';
                break;
            case 'T': 
                ptr_rna[i] = 'A';
                break;
            case 'A': 
                ptr_rna[i] = 'U';
                break;
            default:
                ptr_rna[i] = '\0';
        }
    }

    return ptr_rna;
}