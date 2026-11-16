#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    // adder takes two arguments, which are floating point numbers, and adds them together.
    // The sum is then printed to cout.
    if (argc == 3) {
        double float1{std::stod(argv[1])};
        double float2{std::stod(argv[2])};
        double result {float1 + float2};
        std::cout << result << std::endl;
        return 0; // 0 means success.
    }
    else {
        return 1; // any non-zero value means failure.
    }
}
