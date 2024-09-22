# Compiler and flags
CC = clang
CFLAGS = -fPIC -Wall -Wextra -O3 -Wno-cpp -MMD -MP

# Include directory
INCLUDE_DIR = includes
CFLAGS += -I$(INCLUDE_DIR)

# Source and object directories
SRC_DIR = src
OBJ_DIR = obj

# Find all source files in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Convert source files to object files (change .c to .o)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Output shared library name
LIBRARY = libSIMPL.so

# Default target: build the shared library
all: $(LIBRARY)

# Create the shared library
$(LIBRARY): $(OBJ_FILES)
	$(CC) -shared -o $@ $^

# Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean target: remove all object files and the shared library
clean:
	rm -rf $(OBJ_DIR) $(LIBRARY)

re: clean $(OBJ_DIR) all

.PHONY: all clean
