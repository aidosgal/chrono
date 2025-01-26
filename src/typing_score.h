#ifndef SCORE_TYPING_H_
#define SCORE_TYPING_H_

#include "test_generator.h"

typedef struct {
    Test test;
    float wpm;
    float accuracy;
} Score;

Score score_typing_test(const char *user_input, Test test, float duration_sec);

#endif // !SCORE_TYPING_H_
