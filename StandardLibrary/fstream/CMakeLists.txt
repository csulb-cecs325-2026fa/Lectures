cmake_minimum_required(VERSION 3.28)
project(fstream)

set(CMAKE_CXX_STANDARD 17)

add_executable(fstream main.cpp)

# Make the sample input available when running from the build directory.
configure_file(numbers.txt numbers.txt COPYONLY)
