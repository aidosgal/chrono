#include <stdio.h>
#include <stdlib.h>
#include "test_generator.h"

// TODO: start typing test
// TODO: calculate typing test results
// TODO: generate typing tests from the file

int main(void) {
    printf("Welcome to the Chorono | CLI Typing Test!\n");
    Test test = generate_test(1, 10);
    printf("%s", test.text);
    return 0;
}
