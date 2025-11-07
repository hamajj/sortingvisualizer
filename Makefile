CC = gcc
CFLAGS = -Wall -O2 -Iinclude
LDFLAGS = -lraylib -lm -ldl -pthread

SRC = src/main.c src/sort.c
OBJ = $(SRC:.c=.o)
TARGET = sorting_visualizer

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

.PHONY: all clean
