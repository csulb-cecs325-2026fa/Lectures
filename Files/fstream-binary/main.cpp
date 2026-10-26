#include <cstddef>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>

int main() {
    // We can open a file in binary mode to read it as a stream of bytes,
    // without automatically decoding it with >>.
    // numbers.txt still contains text: binary mode does not change its
    // representation or interpret its characters as numeric values.
    std::ifstream input {"numbers.bin", std::ios::binary};
    if (!input) {
        std::cerr << "Could not open numbers.bin for reading.\n";
        return 1;
    }
    std::cout << "Opened numbers.bin in binary mode.\n";

    // In binary mode, instead of using >> to extract TEXT and convert it
    // into values, we read BYTES into a buffer, and then manually convert
    // those bytes into our expected value.

    // A buffer could be an array, or just a variable of the the size
    // we expect to read.
    // Since C++ numeric types don't have fixed sizes, we can use
    // alternate types if we need a very specific size.

    std::int32_t value {}; // a 32-bit (4-byte) integer.

    // ifstream::read() attempts to fill the requested number of bytes into the
    // given buffer, identified via a pointer to a block of RAM that can fit
    // the size you are reading.
    input.read(reinterpret_cast<char*>(&value), sizeof(value));
    // We can fail in the usual ways, or if we didn't read the expected # of bytes.
    if (input.bad() || input.gcount() != sizeof(value)) {
        std::cerr << "Could not read bytes from numbers.bin.\n";
        return 1;
    }
    // Otherwise we can use the value.
    std::cout << "Value: " << value << std::endl; // Prints "13277755", not "1000000000" as expected...

    // That's because Windows, Mac, and Linux store integers in RAM using "Little Endian"
    // order... (see slides.)

    // Since our file was written in big-endian order, we thus have to swap the bytes
    // to match the system order.
    int32_t realValue {std::byteswap(value)}; // REQUIRES C++ VERSION 23
    // There are ways to only do this if the system is little endian, but you
    // don't need to learn that.

    std::cout << "Byte-corrected: " << realValue << std::endl;

    // If there are more values to read, just repeat this process.
    std::int32_t nextValue{};
    input.read(reinterpret_cast<char*>(&nextValue), sizeof(nextValue));
    if (input.bad() || input.gcount() != sizeof(nextValue)) {
        std::cerr << "Could not read bytes from numbers.bin.\n";
    }
    // You don't need a separate variable for the "real" value, just reassign the original.
    nextValue = std::byteswap(nextValue);
    // Etc.


    // Open a file for binary output.
    std::ofstream output {"numbers2.bin", std::ios::binary};

    // If this was in text mode, the statement:
    // output << 1000000000000;
    // would write 13 bytes to the file. But we'll write it with just 4 bytes.

    // First, we decide what byte order our file should use. Traditionally we use
    // big endian ("natural" ordering).
    // Since our realValue is not in this order, we must reverse it.
    int32_t valueToWrite{std::byteswap(realValue)};
    // ofstream::write: give it a pointer to some bytes, and the number of bytes
    // to write, and it will write those bytes.
    output.write(reinterpret_cast<char*>(&valueToWrite), sizeof(valueToWrite));
    output.flush();
    return 0;
}
