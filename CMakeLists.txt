cmake_minimum_required(VERSION 3.13)

project(grep-starter-cpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

# Gather all source files recursively from src directory
file(GLOB_RECURSE SOURCE_FILES 
    src/*.cpp 
    src/*.hpp
)

# Create an executable named 'exe' using the gathered source files
add_executable(exe ${SOURCE_FILES})

