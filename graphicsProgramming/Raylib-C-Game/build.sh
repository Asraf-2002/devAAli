#!/bin/bash

directory="build"

if [ -d "$directory" ]; then
    rm -r $directory
fi

# Generate build system in the build directory
cmake -S . -B build

# Build executable
cmake --build build