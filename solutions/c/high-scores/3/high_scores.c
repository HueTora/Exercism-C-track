#include "high_scores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// Search for highest score 
score search_for_top(const int32_t *scores, size_t scores_len) {
    score top_score = {0, 0};
    for (size_t element = 0; element < scores_len; element++) {
            if (top_score.value < scores[element]) {
                top_score.value = scores[element];
                top_score.index = element;
            }
    }
    return top_score;
}

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    
    score top_score = search_for_top(scores, scores_len);
    return top_score.value;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    
    size_t top_scores_tot = 0;
    score top_score;
    
    top_scores_tot = (scores_len < 3) ? scores_len : 3;
    
    // Copies array of scores
    int32_t *copy_of_scores = (int32_t *)malloc(scores_len * sizeof(int32_t));
    if (copy_of_scores == NULL) printf("There was a problem allocating memory");
    memcpy(copy_of_scores, scores, scores_len * sizeof(int32_t));

    for (size_t i = 0; i < top_scores_tot; i++) {
        top_score = search_for_top(copy_of_scores, scores_len);
            
        // write element to output 
        output[i] = top_score.value;
    
        // '0' current highest score from 'copy_of_scores'
        copy_of_scores[top_score.index] = 0;
    }
    
    free(copy_of_scores);

    return top_scores_tot;
}
