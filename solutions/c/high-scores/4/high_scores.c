#include "high_scores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t best_score = 0;
    
      for (size_t i = 0; i < scores_len; i++) {
          if (best_score < scores[i]) best_score = scores[i];
      }
    return best_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    
    size_t top_scores_tot = 0;
    top_scores_tot = (scores_len < 3) ? scores_len : 3;
    
    for (size_t i = 0; i < scores_len; i++) {
       if (output[0] < scores[i]){
           output[2] = output[1];
           output[1] = output[0];
           output[0] = scores[i];
       } else if (output[1] < scores[i]) {
           output[2] = output[1];
           output[1] = scores[i];
       } else if (output[2] < scores[i]) output[2] = scores[i];
    }
    
    return top_scores_tot;
}
