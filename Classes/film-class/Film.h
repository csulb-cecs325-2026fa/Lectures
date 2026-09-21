//
// Created by neald on 2/26/2025.
//

#ifndef FILM_H
#define FILM_H
#include <string>

class Film {
    // By default, the members of a class are private -- they cannot be referred to
    // outside of this class.
    // Traditionally, private fields are prefixed with m_.
    std::string m_title;
    int m_releaseYear;
    int m_duration;
    std::string m_rating;

public:
    // CONSTUCTORS: how does someone create a Film?
    Film(const std::string& title, int releaseYear, int duration, const std::string& rating);
    // Someone can create a film with a title, release year, duration, and rating.

    // METHODS: what can we do with a Film?
    bool isFeatureLength();

    // Accessors: we can retrieve individual fields of a Film, if that might be
    // helpful for the public to know.
    const std::string& getTitle();
    int getReleaseYear();
    int getDuration();
    const std::string& getRating();

    // Mutators: if we want to allow it, the public can change the values of our
    // fields, after we check that they are valid values.
    void setTitle(const std::string& title);
    void setReleaseYear(int releaseYear);
    void setDuration(int duration);
    void setRating(const std::string& rating);
};
#endif //FILM_H
