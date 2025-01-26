CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

zet: src/main.c
	$(CC) $(CFLAGS) -I. -o ./bin/chrono src/main.c -lm
