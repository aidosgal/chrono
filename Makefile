CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
TARGET=./build/chrono
SOURCES=src/main.c src/test_generator.c src/typing_score.c src/typing_test.c
BUILD_DIR=build
INSTALL_DIR=/usr/local/bin

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. -o $(TARGET) $(SOURCES) -lm

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

install: $(TARGET)
	sudo install -m 755 $(TARGET) $(INSTALL_DIR)/chrono

uninstall:
	sudo rm -f $(INSTALL_DIR)/chrono

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean install uninstall
