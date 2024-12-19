# Makefile for building the writer application

# Compiler and flags
CC=$(CROSS_COMPILE)gcc
CFLAGS=-Wall -Werror

# Targets
TARGET=writer
SRC=writer.c
OBJ=$(SRC:.c=.o)

.PHONY: all clean

# Default target
all: $(TARGET)

# Build the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the object file
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)

