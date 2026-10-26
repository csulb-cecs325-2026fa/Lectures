#include <array>
#include <cstddef>
#include <cstdio>
#include <iostream>

#include <fcntl.h>  // open(), O_RDONLY
#include <unistd.h> // read(), close(), ssize_t

int main() {
    // File names are relative to the program's working directory.
    // CMake copies the same sample data used in the fstream lecture
    // into the build directory. Locate that copy before running.

    // open() attempts to open the file for reading.
    // It returns a file descriptor: a nonnegative integer identifying
    // an open I/O resource in this process. -1 means opening failed.
    int fd {open("numbers.txt", O_RDONLY)};
    if (fd == -1) {
        // perror() prints our message and the reason for the failure.
        std::perror("Could not open numbers.txt");
        return 1;
    }
    std::cout << "Opened numbers.txt with file descriptor " << fd << ".\n";

    // We provide the memory where read() will put the bytes.
    // Keep this buffer small so we can see several separate reads.
    std::array<char, 8> buffer {};
    ssize_t bytesRead {};
    std::size_t totalBytes {0};

    // read(fd, destination, capacity) requests UP TO capacity bytes.
    // A positive result tells us how many bytes actually arrived.
    // Each read continues from where the previous one stopped.
    while ((bytesRead = read(fd, buffer.data(), buffer.size())) > 0) {
        std::cout << "Read " << bytesRead << " bytes: [";

        // read() does not add a null terminator. Display only the bytes
        // it supplied, rather than treating the buffer as a C string.
        std::cout.write(buffer.data(), bytesRead);
        std::cout << "]\n";
        totalBytes += static_cast<std::size_t>(bytesRead);
    }

    // Unlike input >> value, read() does not interpret numbers or skip
    // whitespace. Spaces and newlines are bytes too, and a number's
    // characters can be split across two reads. Find the 10 in this demo.
    // A short read is valid. Only 0 means we reached the end of the file.
    // ssize_t is signed so it can also represent the error result -1.
    int result {0};
    if (bytesRead == -1) {
        std::perror("Could not read numbers.txt");
        result = 1;
    } else {
        std::cout << "End of file. Read " << totalBytes << " bytes in all.\n";
    }

    // Even if reading failed, we still own the open file and must close it.
    // Unlike an ifstream, fd is just an int. Destroying it does not close
    // the file. Every path after a successful open needs cleanup.
    if (close(fd) == -1) {
        std::perror("Could not close numbers.txt");
        return 1;
    }
    std::cout << "Closed file descriptor " << fd << ".\n";

    // How could an RAII class take over this cleanup responsibility?
    return result;
}
