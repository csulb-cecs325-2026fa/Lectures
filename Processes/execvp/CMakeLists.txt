cmake_minimum_required(VERSION 3.22.1)
project(execvp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(execvp main.cpp)

# Reuse the existing adder source and build it alongside this example.
add_executable(adder ../adder/main.cpp)
add_dependencies(execvp adder)
