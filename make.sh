#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Find all .c files in the src directory
SRC_FILES=$(find ./src -name '*.c')

# Compile the project
gcc -I./include $SRC_FILES main.c -o build/xsc

