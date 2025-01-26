CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
TARGET=./build/chrono
SOURCES=src/main.c src/test_generator.c
BUILD_DIR=build

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. -o $(TARGET) $(SOURCES) -lm

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean

