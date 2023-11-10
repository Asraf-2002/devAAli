# Include Raylib package
find_package(Raylib REQUIRED)

find_library(MYLIB raylib)
#message(STATUS "Path of raylib is : ${MYLIB}")

# Add your source files (e.g., main.cpp)
add_executable(snake main.cpp)

# Link the Raylib library to your project
target_link_libraries(snake PRIVATE ${MYLIB})