#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "typing_score.h"

Score score_typing_test(const char *user_input, Test test, float duration_sec) {
    int correct_chars = 0;
    int total_chars = strlen(test.text);
    int input_len = strlen(user_input);
    
    for (int i = 0; i < total_chars && i < input_len; i++) {
        if (tolower(test.text[i]) == tolower(user_input[i])) {
            correct_chars++;
        }
    }
    
    int word_count = 0;
    int in_word = 0;
    for (int i = 0; i < input_len; i++) {
        if (!isspace(user_input[i]) && !in_word) {
            word_count++;
            in_word = 1;
        } else if (isspace(user_input[i])) {
            in_word = 0;
        }
    }
    
    float duration_minutes = (duration_sec > 0) ? (duration_sec / 60.0f) : 1.0f;
    
    float accuracy = (total_chars > 0) ? 
        ((float)correct_chars / total_chars * 100.0f) : 0.0f;
    
    float wpm = word_count / duration_minutes;
    
    Score result = {
        .test = test,
        .wpm = wpm,
        .accuracy = accuracy,
    };
    
    return result;
}
