# Create an executable target for your project
add_executable(MyProject
    foo.cpp
    fun.cpp
    main.cpp
)

# Add the 'include' directory to the include directories
target_include_directories(MyProject PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Optionally, set additional configuration, e.g., linking libraries