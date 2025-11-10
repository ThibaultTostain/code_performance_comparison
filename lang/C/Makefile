# Set compiler and flags
CC 		:= gcc
CFLAGS 	:= -std=c17 -O3 -pedantic -Wall -Wextra -Werror -Wvla -I./lib

# Paths
SRC_DIR := src
LIB_DIR := lib
BUILD_DIR := build
BIN_DIR   := $(BUILD_DIR)/bin
DB_DIR    := $(BUILD_DIR)/db
$(BUILD_DIR)/bin:
	mkdir -p $(BUILD_DIR)/bin
$(BUILD_DIR)/db:
	mkdir -p $(BUILD_DIR)/db

# Find sources for lib and src
LIB_SRCS := $(wildcard $(LIB_DIR)/*.c)
SRC_SRCS := $(wildcard $(SRC_DIR)/*.c)

# Output
TARGETS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC_SRCS))
DBS     := $(patsubst $(BIN_DIR)/%, $(DB_DIR)/%.db, $(TARGETS))

# Default - make the programme
all: $(BUILD_DIR)/bin $(BUILD_DIR)/db $(TARGETS)

$(BIN_DIR)/%: $(SRC_DIR)/%.c $(LIB_SRCS)
	$(CC) $(CFLAGS) $< $(LIB_SRCS) -lrt -lm -lsqlite3 -o $@

# Delete output
clean:
	rm -f $(TARGETS)
	rm -f $(DBS)

# Avoid conflicts
.PHONY: all clean
