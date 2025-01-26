#include <stdio.h>
#include <stdlib.h>
#include "test_generator.h"
#include "typing_test.h"

int main(void) {
    printf("Welcome to the Chrono | CLI Typing Test!\n");

    int level, word_count;
    char retry;

    do {
        printf("\nSelect a difficulty level:\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &level);

        if (level < 1 || level > 3) {
            printf("Invalid level. Please choose a number between 1 and 3.\n");
            continue;
        }

        printf("Enter the number of words for the test (max 60): ");
        scanf("%d", &word_count);

        if (word_count < 1 || word_count > 60) {
            printf("Invalid number of words. Please choose a number between 1 and 60.\n");
            continue;
        }

        Test test = generate_test(level, word_count);

        printf("\nStarting typing test...\n");
        Score result = start_typing_test(test);

        printf("\nTyping Test Results:\n");
        printf("WPM: %.2f\n", result.wpm);
        printf("Accuracy: %.2f%%\n", result.accuracy);

        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &retry);
    } while (retry == 'y' || retry == 'Y');

    printf("\nThank you for using Chrono | CLI Typing Test. Goodbye!\n");
    return 0;
}

