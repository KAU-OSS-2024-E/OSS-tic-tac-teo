# Makefile for compiling TicTacToe game

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Target executable name
TARGET = TicTacToe

# Source files
SRCS = src/main.c src/main_menu.c src/game_logic.c src/move_cursor.c src/win_game.c src/game_rules.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target to build
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
