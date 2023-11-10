# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Optionally, set C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define your project and its version
project(
    muslizer
    VERSION 1.0
    DESCRIPTION "My music visualizer project"
    LANGUAGES CXX
)

add_subdirectory(src)
