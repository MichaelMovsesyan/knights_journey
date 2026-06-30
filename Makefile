# Compiler
CC = gcc

# Executable
TARGET = main

# Sources
SRC = main.c knight.c
OBJ = $(SRC:.c=.o)

# Compiler flags
CFLAGS = -Wall -Wextra -std=c17 -g
CFLAGS += -I./raylib/src

# Link against the local raylib build
RAYLIB = ./raylib/build/raylib/libraylib.a

LDLIBS = $(RAYLIB) -lm -ldl -lpthread -lrt -lX11

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild