#include <iostream>

// A Film consists of a title, a release year, a duration, and a rating.
void printFilm(const std::string& title, int releaseYear, int duration, const std::string& rating) {
    std::cout << title << " (" << releaseYear << "), rated " << rating;
}

// According to the Oscars, a film is feature length if it is at least 40 minutes long.
bool isFeatureLength(int duration) {
    return duration >= 40;
}

int main() {
    std::string dogMan {"Dog Man"};
    int dogManYear {2025};
    int dogManDuration {89};
    std::string dogManRating {"PG"};
    printFilm(dogMan, dogManYear, dogManDuration, dogManRating);
    std::cout << isFeatureLength(dogManDuration) << std::endl;

    // What if we write other functions involving films?
    //      Write the function "myKidsWillWatch". My kids will only watch films that are less than 20 years old,
    //          rated G or PG, and less than 2 hours long.
    //
    // What if we decide a film requires more information?
    // Do we really want to copy and paste all these parameters across dozens of functions?
    // What if we want to change one of the parameter types for all those functions?

    // We are stressing over the DETAILS of what a film is, rather than deal with
    // the abstract thought of a Film as a type of data. This code will be very difficult
    // to scale and maintain.
    return 0;
}
