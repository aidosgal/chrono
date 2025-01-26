#ifndef TEST_GENERATOR_H_
#define TEST_GENERATOR_H_

#define LEVEL_EASY 0;
#define LEVEL_MEDIUM 1;
#define LEVEL_HARD 2;

#define MAX_WORDS 100;
#define MAX_WORD_LENGTH 50
#define MAX_WORDS_PER_LEVEL 100

typedef struct {
    const char *text;
    int level;
} Test;

/*
 * @param level: The difficulty level (LEVEL_EASY, LEVEL_MEDIUM, LEVEL_HARD) 
 * @return: A Test structure containing the test details
 */
Test generate_test(int level, int size_words);

/*
 * @param size_words: The number of words to include in the test text.
 * @return: A Test text from txt file
 */
char* text_from_file(const char *file_path, int size_words, int level);

#endif // !TEST_GENERATOR_H
