# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define your project and its version
project(test VERSION 1.0)

# Optionally, set C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the Raylib package config file
#set(RAYLIB_DIR "$~/raylib/build/raylib")

# Include Raylib package
find_package(Raylib REQUIRED)

find_library(MYLIB raylib)
message(STATUS "Path of raylib is : ${MYLIB}")

# Add your source files (e.g., main.cpp)
add_executable(test main.cpp)

# Link the Raylib library to your project
target_link_libraries(test PRIVATE ${MYLIB})
