# Compiler and flags
CC      := gcc
CFLAGS  := -g -Wall -Wextra

# Executable name
BIN     := words

# Source files
SRC     := main.c word_count.c ../map.c ../recurse.c
OBJ     := $(SRC:.c=.o)

# Default target
all: $(BIN)

# Build executable
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Pattern rule for compiling .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

../map.o: ../map.c
	$(CC) $(CFLAGS) -c $< -o $@

../recurse.o: ../recurse.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(BIN) $(OBJ)