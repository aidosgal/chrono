#include "test_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* text_from_file(const char* file_path, int size_words, int level) {
     FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    const char *level_identifiers[] = {
        "# Easy Passages",
        "# Medium Passages",
        "# Hard Passages"
    };

    char line[1024];
    int found_level = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, level_identifiers[level])) {
            found_level = 1;
            break;
        }
    }

    if (!found_level) {
        fclose(file);
        fprintf(stderr, "Level not found in file\n");
        return NULL;
    }

    char passage[1024] = {0};
    while (fgets(line, sizeof(line), file) && line[0] != '#') {
        strcat(passage, line);
    }

    fclose(file);

    char *words[MAX_WORDS_PER_LEVEL];
    int word_count = 0;

    char *token = strtok(passage, " \n");
    while (token && word_count < MAX_WORDS_PER_LEVEL) {
        words[word_count++] = token;
        token = strtok(NULL, " \n");
    }

    if (size_words > word_count) {
        size_words = word_count; 
    }

    srand(time(NULL));

    char *result = malloc(size_words * (MAX_WORD_LENGTH + 1));
    result[0] = '\0';

    for (int i = 0; i < size_words; i++) {
        int index = rand() % word_count;
        strcat(result, words[index]);
        if (i < size_words - 1) {
            strcat(result, " ");
        }
    }

    return result;
}

Test generate_test(int level, int size_words) {
    char* text = text_from_file("./resources/tests.txt", size_words, level);

    Test test = {
        .text = text,
        .level = level
    };

    return test;
}
