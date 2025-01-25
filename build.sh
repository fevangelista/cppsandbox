#!/usr/bin/env bash

# 1. Create a build directory
rm -rf build
mkdir build
cd build

# 2. Run CMake configure step (assumes there's a top-level CMakeLists.txt in ../ )
cmake ..

# 3. Build all targets (i.e., all examples)
cmake --build .

# 4. Copy the built examples to the top-level directory
cp main ..
