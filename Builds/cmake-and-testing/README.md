# Event summary: building, testing, and debugging

A C++23 lecture example for the larger-projects module. The input is a fixed
vector of events. There is no file-format implementation to complete.

**This is a debugging exercise. The initial program deliberately contains one
logic error that the five initial tests do not catch.**

## Project layout

```text
Builds/
  CMakeLists.txt                 project targets and their relationships
  vcpkg.json                    GoogleTest dependency
  include/
    event.h                     the Event data type
    event_stats.h               the statistics interface
  src/
    main.cpp                    the application entry point
    event_stats.cpp             the statistics implementation
  tests/
    CMakeLists.txt              the test executable and test discovery
    event_stats_tests.cpp       five initial tests
  exercises/
    report/
      include/event_report.h    supplied component to integrate
      src/event_report.cpp
    single_event_test.cpp       optional supplied boundary test
  INSTRUCTOR.md                 lesson sequence and intended fixes
```

`event_stats` is a library target. The application and test executable both
link it. Its `PUBLIC` include directory and C++23 requirement also apply to
those targets. Each executable has its own `main()`; GoogleTest supplies the
test executable's entry point.

## Build and run

Open this folder as a CMake project in CLion. Use a Debug configuration.
The GoogleTest build needs vcpkg integration, just like the homework projects.
Set this in the CLion CMake profile, replacing the path with your installation:

```text
-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```

For a terminal build on Linux, macOS, or WSL, start in this folder:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
./build/event_summary
ctest --test-dir build --output-on-failure
```

Use a fresh build directory when changing compilers or adding a toolchain.
If GoogleTest is already installed somewhere CMake searches, the toolchain
option is unnecessary. To build only the application without GoogleTest:

```sh
cmake -S . -B build-app -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_COMPILER=clang++ -DBUILD_TESTING=OFF
cmake --build build-app
./build-app/event_summary
```

The original demonstration prints:

```text
Records: 3
Total event count: 110
Busiest record: 100 events at 20 seconds
```

## 1. Integrate a component

The supplied `printEventSummary` function moves presentation out of `main()`.

1. Copy `event_report.h` from `exercises/report/include/` into `include/`.
   Copy `event_report.cpp` from `exercises/report/src/` into `src/`.
2. Include `event_report.h` in `main.cpp`. Keep the sample vector, but replace
   the output statements with `printEventSummary(std::cout, events);`.
3. Build before changing CMake. Identify which stage reports the problem.
   Why is including the header insufficient?
4. Add `src/event_report.cpp` to the `event_stats` library's source list.
   Rebuild and confirm the output is unchanged.
5. Explain why both executables can use the same library, and why neither
   library source file defines `main()`.

For a separate header-search exercise, temporarily comment out
`target_include_directories` in the top-level CMake file, then rebuild.
Restore it after identifying the error. Compare this with the error in step 3.

## 2. Strengthen the tests

Run the initial five tests and compare them with the promises in `event_stats.h`.
Write a test for a log containing exactly one record. The expected pointer is
the address of that vector's only element. Add the test to
`tests/event_stats_tests.cpp`, or use the supplied file by adding
`../exercises/single_event_test.cpp` to the test executable's source list.

The new test should fail. What does its expected-versus-actual output tell you?
Why did the original sample and all five initial tests succeed?

## 3. Debug the failure

In CLion, debug only the failing test. Set a breakpoint at the start of
`findBusiestEvent`. Inspect the vector, its size, the loop index, and `busiest`.
Step through the function and inspect the call stack. Explain the cause before
changing the implementation.

Fix the problem and rerun the tests. Add tests where the first record has the
largest count and where two records tie. Check that the result still satisfies
the interface's rule for empty input and ties.
