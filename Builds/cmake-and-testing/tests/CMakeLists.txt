find_package(GTest CONFIG REQUIRED)

# The tests have their own executable. GoogleTest supplies its main().
# Both executables link the same event_stats library.
add_executable(event_stats_tests event_stats_tests.cpp)
target_link_libraries(event_stats_tests PRIVATE event_stats GTest::gtest_main)
set_target_properties(event_stats_tests PROPERTIES CXX_EXTENSIONS OFF)

include(GoogleTest)
gtest_discover_tests(event_stats_tests)
