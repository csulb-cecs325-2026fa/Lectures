execvp: supplying arguments to another program

Build and run in Linux, macOS, or WSL. From this project's directory:

    cmake -S . -B build
    cmake --build build --target execvp
    cd build
    ./execvp

Expected output:

    Replacing this program with adder...
    5

CMake builds the existing ../adder/main.cpp as a second executable. Building
the execvp target also builds adder. No copy of adder's source is needed.

In CLion on Windows, use the WSL toolchain. Select the execvp target and set
its working directory to the build directory containing both executables.

Lecture points

- vector<string> stores the program name and its two arguments.
- vector<char*> points to those strings' characters. Its final nullptr marks
  the end of the list and is not counted in adder's argc.
- execvp receives the pointer vector through argv.data(). Passing the string
  vector's data() directly would supply string*, which is the wrong type.
- adder receives argc == 3 and the arguments ./adder, 2, and 3.
- The string storage must stay alive and unchanged while the pointers are used.
- Successful exec replaces this program with adder in the same process.
  There is no fork here. The final process exit status comes from adder.
- If execvp returns, execution failed. Print the error and return 1 from main.
- A bare program name makes execvp search PATH. The example uses ./adder to
  identify the executable in the working directory; PATH is not used for it.

Demonstrations

1. Change 2 and 3 in main.cpp, rebuild, and observe adder's new sum.
2. Change ./adder to ./missing-adder, rebuild, and observe the error and exit
   status 1. Restore ./adder afterward.
3. To demonstrate PATH lookup without changing code, temporarily replace the
   arguments with {"ls", "-l"}, rebuild, and run. Restore the adder arguments
   afterward.

For a generator with separate configuration directories, such as Ninja Multi-
Config, run from the configuration directory containing the executables.
