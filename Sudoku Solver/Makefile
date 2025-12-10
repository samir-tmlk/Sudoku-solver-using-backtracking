CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = sudoku_solver
SRC = sudoku_solver.c

# Default target
all: $(TARGET)

# Compile
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean binaries
clean:
	rm -f $(TARGET)

# Run with the provided example file
run: $(TARGET)
	./$(TARGET) sudoku.txt