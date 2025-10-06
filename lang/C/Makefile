# Set compiler and flags
CC 		:= gcc
CFLAGS 	:= -std=c17 -O3 -pedantic -Wall -Wextra -Werror -Wvla -I./lib

# Paths
SRC_DIR := src
LIB_DIR := lib
BUILD_DIR	:= build/bin

# Find sources for lib and src
LIB_SRCS := $(wildcard $(LIB_DIR)/*.c)
SRC_SRCS := $(wildcard $(SRC_DIR)/*.c)

# Name for binaries
TARGETS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRC_SRCS))

# Default - make the programme
all: $(TARGETS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c $(LIB_SRCS)
	$(CC) $(CFLAGS) $< $(LIB_SRCS) -lrt -lm -o $@

# Delete binaries
clean:
	rm -f $(TARGETS)

# Avoid conflicts
.PHONY: all clean
