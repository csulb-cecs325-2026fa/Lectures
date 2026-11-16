#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

std::vector<int> randomVector(int start, int end) {
    std::random_device rd {};
    std::default_random_engine engine {rd()};
    std::uniform_int_distribution<int> range {start, end};

    std::vector<int> r {};
    for (size_t i {0}; i < 1000000; ++i) {
        r.push_back(range(engine));
    }
    return r;
}

void generateSortAndPrint(int vectorNumber, int startValue, int endValue) {
    std::cout << "Generating vector " << vectorNumber << std::endl;
    std::vector<int> vec {randomVector(startValue, endValue)};
    std::cout << "Sorting vector " << vectorNumber << std::endl;
    std::sort(vec.begin(), vec.end());

    std::cout << "Vector " << vectorNumber << ":" << std::endl;
    for (auto itr = vec.begin(); itr < vec.begin() + 100; ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    // This program generates two random vectors, sorts them, and prints them.

    // We can take advantage of 2 CPU cores to sort two vectors in parallel.
    // First, we create a second "thread" to start running the generatePrintAndSort function.
    std::thread t2 {generateSortAndPrint, 1, 1, 500000};
    // This causes a new thread to start running generatePrintAndSort, passing an argument of 1.
    // That thread immediately starts running; the "main thread" continues to the next line.

    // The main thread will also call generatePrintAndSort to create vector number 2.
    generateSortAndPrint(2, 500001, 9000000);


    // Don't let the program terminate until the second thread is also done.
    //t2.join();
    // join(): wait for the thread to terminate before continuing.

    return 0;
}
