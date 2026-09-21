#include <iostream>
struct Film {
    std::string title;
    int releaseYear;
    int duration;
    std::string rating;
}; // note the semi colon here.

// Print a film, which is taken as a const reference because it is large,
// we don't mutate it, and we can't deal with nullptr.
void printFilm(const Film& film) {
    std::cout << film.title << " (" << film.releaseYear << "), rated " << film.rating;
}

// According to the Oscars, a film is feature length if it is at least 40 minutes long.
bool isFeatureLength(const Film& film) {
    return film.duration >= 40;
}

int main() {
    Film f {"Dog Man", 2025, 87, "PG"};
    f.duration = -10;

    printFilm(f);
    std::cout << isFeatureLength(f) << std::endl;
    return 0;
}
