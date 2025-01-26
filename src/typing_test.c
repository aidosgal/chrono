#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include "typing_test.h"

#define ANSI_GREEN "\033[32m"
#define ANSI_RED "\033[31m"
#define ANSI_GRAY "\033[90m"
#define ANSI_RESET "\033[0m"

void set_terminal_raw_mode(void) {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restore_terminal_mode(void) {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void display_typing_progress(const char* typing_text, const char* user_input, size_t text_len) {
    printf("\r");
    
    size_t input_len = strlen(user_input);
    for (size_t i = 0; i < input_len; i++) {
        if (i < text_len) {
            if (user_input[i] == typing_text[i]) {
                printf(ANSI_GREEN "%c" ANSI_RESET, typing_text[i]);
            } else {
                printf(ANSI_RED "%c" ANSI_RESET, user_input[i]);
            }
        }
    }
    
    for (size_t i = input_len; i < text_len; i++) {
        printf("_");
    }
    
    fflush(stdout);
}

Score start_typing_test(Test test) {
    set_terminal_raw_mode();
    
    char user_input[1024] = {0};
    const char *typing_text = test.text;
    
    printf("Type the following text:\n%s\n", typing_text);
    
    size_t text_len = strlen(typing_text);
    printf("\n");
    
    time_t start_time = time(NULL); 
    size_t input_len = 0; 
    int ch;
    
    while (input_len < text_len) {
        ch = getchar();
        
        if (ch == 27) {
            break;
        }
        
        if (ch == 127 || ch == 8) {
            if (input_len > 0) {
                input_len--;
                user_input[input_len] = '\0';
            }
        }
        else if (input_len < text_len) {
            if (ch == typing_text[input_len]) {
                user_input[input_len] = ch;
                input_len++;
            }
        }
        
        display_typing_progress(typing_text, user_input, text_len);
        
        if (input_len == text_len) {
            break;
        }
    }
    
    restore_terminal_mode();
    
    time_t end_time = time(NULL); 
    float duration_sec = difftime(end_time, start_time); 
    
    user_input[input_len] = '\0';
    
    Score result = score_typing_test(user_input, test, duration_sec);
    
    free((char*)test.text);
    
    return result;
}
