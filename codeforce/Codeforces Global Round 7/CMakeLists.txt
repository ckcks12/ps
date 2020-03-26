cmake_minimum_required(VERSION 3.13)  # CMake version check
project(codeforce)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

include_directories(/usr/local/include/bits)
file(GLOB SOURCE_FILES ./*.cc)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(codeforce ${SOURCE_FILES})
