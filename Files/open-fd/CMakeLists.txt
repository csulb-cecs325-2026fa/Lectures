cmake_minimum_required(VERSION 3.28)
project(open_fd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT UNIX)
    message(FATAL_ERROR "Build this POSIX demo on Linux, macOS, or with a WSL toolchain.")
endif()

add_executable(open_fd main.cpp)

# As in the fstream demo, run from the source or build directory.
configure_file(numbers.txt numbers.txt COPYONLY)
