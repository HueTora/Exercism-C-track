#include "high_scores.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int32_t compare(const void *a, const void *b) {
    return *(int32_t *)a - *(int32_t *)b;
}

// return element from sorted array by index
int32_t element_from_sorted_arr(const int32_t *scores, size_t scores_len, int index) {
    
    int32_t *copy_of_scores = (int32_t *)malloc(scores_len * sizeof(int32_t));
    if (copy_of_scores == NULL) printf("There was a problem allocating memory");
    
    memcpy(copy_of_scores, scores, scores_len * sizeof(int32_t));
    qsort(copy_of_scores, scores_len, sizeof(int32_t), compare);
    
    int32_t element = copy_of_scores[index];
    
    free(copy_of_scores);
    
    return element;
}

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    return element_from_sorted_arr(scores, scores_len, scores_len - 1);
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    size_t top_scores_tot = 0;

    top_scores_tot = (scores_len < 3) ? scores_len : 3;

    for (size_t i = 0; i < top_scores_tot; i++) {
        output[i] = element_from_sorted_arr(scores, scores_len, scores_len - (i+1));
    }

    return top_scores_tot;
}
