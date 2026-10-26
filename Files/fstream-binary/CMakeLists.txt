cmake_minimum_required(VERSION 3.28)
project(fstream_binary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(fstream_binary main.cpp)

# As in open-fd, make the sample available in the build directory.
configure_file(numbers.bin numbers.bin COPYONLY)
