#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

// Demonstrate calling another program and passing command line arguments.
// In this case, the "adder" lecture example is called. CMake copies
// the compiled "adder" executable to the same location as this program's
// executable.
int main() {
    // These strings become argv[0], argv[1], and argv[2] in adder.
    std::vector<std::string> arguments {"./adder", "2", "3"};

    // execvp needs pointers to characters, rather than std::string objects.
    // Each pointer refers to the characters stored in one of our strings.
    std::vector<char*> argVector;
    for (auto& argument : arguments) {
        argVector.push_back(argument.data());
    }
    argVector.push_back(nullptr); // Marks the end of the argument list.

    // Keep arguments alive and unchanged while these pointers refer to it.
    std::cout << "Replacing this program with adder..." << std::endl;

    // argVector[0] is the name of the program to run. argVector.data()
    // returns a pointer to the elements of argVector, which is what
    // execvp expects.
    execvp(argVector[0], argVector.data());

    // Successful exec never returns. We reach here only if it failed.
    std::perror("execvp");
    return 1;
}
