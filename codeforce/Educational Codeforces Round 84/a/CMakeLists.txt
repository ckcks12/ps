cmake_minimum_required(VERSION 3.13)  # CMake version check
project(a)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

include_directories(/usr/local/include/bits)
set(SOURCE_FILES main.cc)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(a ${SOURCE_FILES})
