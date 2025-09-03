#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {

    size_t length = strlen(dna) + 1;

    char *ptr_rna = calloc(length + 1, sizeof(char));
    ptr_rna = memset(ptr_rna, '\0', length + 1);
    
    for(size_t i = 0; i < length; i++) {
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
        }
        
    }

    return ptr_rna;
}