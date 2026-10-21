#include <fstream>
#include <iostream>

int main() {
    // File names are relative to the program's working directory.
    // CMake copies numbers.txt to the build directory for us.
    // Locate numbers.txt in the project root directory, THEN compile the program,
    // and then find the numbers.txt file copied by CMake to the build directory.

    // Like std::cin, an ifstream supplies values with >>, but from a file instead of the console.
    // Its constructor opens a file for reading.
    std::ifstream input {"numbers.txt"};
    if (!input) {
        std::cerr << "Could not open numbers.txt for reading.\n";
        return 1;
    }

    int count {0};
    double total {0.0};
    double value {};

    // The >> operator reads a value from the input file.
    // It assumes the file is formatted as TEXT; more on this later.

    // Try to read a number; enter the loop only if the read succeeded.
    // Spaces and newlines both separate numbers.
    // This loop will terminate when we reach the end of the file and can't >> another double value.
    while (input >> value) {
        std::cout << "Read: " << value << '\n';
        total += value;
        ++count;
    }

    // Reaching the end is normal. Other input failures are errors.
    if (input.bad() || !input.eof()) {
        std::cerr << "Could not read a number from numbers.txt.\n";
        return 1;
    }

    // Like std::cout, an ofstream receives values with <<.
    // Opening this way creates the file, or replaces its old contents.
    std::ofstream output {"summary.txt"};
    if (!output) {
        std::cerr << "Could not open summary.txt for writing.\n";
        return 1;
    }

    output << "Count: " << count << '\n';
    output << "Total: " << total << '\n';
    if (count > 0) {
        output << "Average: " << total / count << '\n';
    } else {
        output << "Average: no numbers to average\n";
    }

    // Streams buffer output, instead of writing immediately.
    // We must "flush" a stream to force it to write to the drive,
    // and so we can check for write errors.
    output.flush();
    if (!output) {
        std::cerr << "Could not write the summary to summary.txt.\n";
        return 1;
    }

    std::cout << "Wrote summary.txt.\n";

    // RAII: the stream destructors close both files when main ends.
    // This also happens if we return early after an error.
    return 0;
}
