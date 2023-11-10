#set project name here
set(project_name "raylib-c-game")

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Optionally, set C++ standard (e.g., C++17)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define your project and its version
project(
    ${project_name}
    VERSION 1.0
    DESCRIPTION "My classic game project"
    LANGUAGES C
)

add_subdirectory(src)
