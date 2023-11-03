# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c99 -Wall -Wextra -pedantic

# Source file
SRC = main.c

# Executable file
EXEC = double_linked_list

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC).exe

.PHONY: all clean