#include "binary_search.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {

    
    int L = 0;
    int R = length - 1;
    int m = 0;
    if (length == 0) return NULL;
    
    while (R != L) {
        m = L + ceil((R-L+1)/2);
        printf("znaleziony element: %d, szukany: %d  indeksy -> L: %d R: %d\n", *(arr+m), value, L, R);
        if (*(arr+m) == value) return (int *)arr+m;
        else if (*(arr+m) < value) L = m+1;
        else R = m - 1;
    }
    if (*(arr+L) == value) return (int *)arr+L;
    else return NULL;

}
 
