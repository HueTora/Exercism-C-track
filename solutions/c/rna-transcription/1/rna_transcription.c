#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {

    int length = 0;
    for(; *dna!='\0'; dna++) {
        length++;
    }

    char *ptr_rna = calloc(length, sizeof(char));
    dna -= length;
    
    for(int i = 0; i < length; i++) {
        switch(*dna) {
            case 'G':
                *ptr_rna = 'C';
                break;
            case 'C': 
                *ptr_rna = 'G';
                break;
            case 'T': 
                *ptr_rna = 'A';
                break;
            case 'A': 
                *ptr_rna = 'U';
                break;
        }

        ptr_rna++;
        dna++;
    }

    return ptr_rna - length;
}