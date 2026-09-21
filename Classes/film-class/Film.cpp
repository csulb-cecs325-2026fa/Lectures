//
// Created by neald on 2/26/2025.
//

#include "Film.h"

Film::Film(const std::string &title, int releaseYear, int duration, const std::string &rating)
    : m_title{title}
{
    // Enforce the invariant conditions, and set reasonable defaults if they are violated.
    if (releaseYear > 0) {
        m_releaseYear = releaseYear;
    }
    else {
        m_releaseYear = 2025;
    }

    if (duration > 0) {
        m_duration = duration;
    }
    else {
        m_duration = 60;
    }

    if (rating == "G" || rating == "PG" || rating == "PG-13" || rating == "R" ||
        rating == "NC-17") {
        m_rating = rating;
    }
    else {
        m_rating = "PG";
    }
}

bool Film::isFeatureLength() {
    return m_duration >= 40;
}

const std::string & Film::getTitle() {
    return m_title;
}

int Film::getReleaseYear() {
    return m_releaseYear;
}

int Film::getDuration() {
    return m_duration;
}

const std::string& Film::getRating() {
    return m_rating;
}

void Film::setTitle(const std::string &title) {
    m_title = title;
}

void Film::setReleaseYear(int releaseYear) {
    if (releaseYear > 0) {
        m_releaseYear = releaseYear;
    }
}

void Film::setDuration(int duration) {
    if (duration > 0) {
        m_duration = duration;
    }
}

void Film::setRating(const std::string &rating) {
    if (rating == "G" || rating == "PG" || rating == "PG-13" || rating == "R" ||
        rating == "NC-17") {
        m_rating = rating;
    }
}
