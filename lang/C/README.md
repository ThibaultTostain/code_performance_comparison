# C Project

## Project Structure
```plaintext
.
├── 📁 C/               # Main folder for the C project
│   ├── 📁 build/        # Build output (not tracked by Git)
│   │   └── 📁 bin/      # Compiled binaries
│   ├── 📁 lib/          # Utility functions for tests
│   └── 📁 src/          # Source files for main functions
├── 📄 README.md         # README specific to the C project
└── 📄 Makefile          # Makefile for building the project
```

## How to Run the Project
```bash
make                # Compile the project
./build/bin/<fct>   # Run the compiled binary (replace <fct> with the desired function)
make clean          # Clean the build directory
```

## Compiler Flags Used

| Flag | Description |
| --- | --- |
| `-std=c17` | Use the C17 standard (2017 version of C) |
| `-O3` | Enable the highest level of optimization |
| `-pedantic` | Enforce strict ISO C compliance |
| `-Wall` | Enable most common warnings |
| `-Wextra` | Enable additional warnings beyond `-Wall` |
| `-Werror` | Treat all warnings as errors and stop compilation |
| `-Wvla` | Warn about Variable Length Arrays (VLAs); prefer `malloc()` for dynamic arrays |
| `-I./lib` | Specify the `./lib/` directory for header file inclusion |
| `-lrt` | Link the real-time library (for time-related functions) |
| `-lm` | Link the math library (for mathematical functions) |

## Time Measurement

### Manual Implementation
To measure the execution time of functions, I use the `time.h` library and the `clock()` function. While `clock()` is not the most precise method, especially compared to `clock_gettime(CLOCK_MONOTONIC, ...)` on Linux, it offers better cross-platform compatibility. For higher precision, platform-specific solutions like `clock_gettime` are recommended, but they may not work on all operating systems. For now, I use `clock()` for simplicity and compatibility.

### Benchmark Libraries
I am aware of existing benchmarking libraries, but I prefer to implement my own solution for learning purposes. This may change in the future.

## Some C code information

1. The function `strdup(str)` alloc memory like `malloc(strlen(str) + 1)` and duplicate the string inside of it. So use `free()` at the end. You also have to add `#define _GNU_SOURCE`.