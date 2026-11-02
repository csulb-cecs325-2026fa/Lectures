cmake_minimum_required(VERSION 3.21)
project(EventSummary LANGUAGES CXX)

# This target contains the reusable part of our program. It has no main().
add_library(event_stats src/event_stats.cpp)
target_include_directories(event_stats PUBLIC include)
target_compile_features(event_stats PUBLIC cxx_std_23)

# The executable calls functions from event_stats. Linking the library also
# gives this target its PUBLIC include directory and C++23 requirement.
add_executable(event_summary src/main.cpp)
target_link_libraries(event_summary PRIVATE event_stats)

# BUILD_TESTING defaults to ON. Turn it off to build without GoogleTest.
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
