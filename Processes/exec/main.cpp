#include <cstring>
#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    // execl: execute another program in the space of this program.
    // Arguments:
    // 1. Path to the program to execute.
    // 2. The name of the executable file to run.
    // 3. Zero or more command-line arguments, as they would have been typed on a command
    //    line terminal when running the program.
    // 4. The command-line arguments ALWAYS end with a nullptr.
    // If execl succeeds, the next line of code does NOT run.
    execl("/bin/ls", "ls", "-l", nullptr);
    // If we get here, we know there was an error.
    std::perror("execl");
    return 1;
}
