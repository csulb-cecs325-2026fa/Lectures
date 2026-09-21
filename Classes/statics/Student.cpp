//
// Created by neald on 3/5/2025.
//

#include "Student.h"

// Initialize the static m_nextStudentId with its starting value.
// We DO NOT repeat the static keyword.
int Student::m_nextStudentId {1};


// We can only refer to m_nextStudentId in any Student functions, because it
// is private to the Student class.
Student::Student(const std::string &firstName, const std::string &lastName)
    // Assign this student with the "next student ID",
    : m_id {m_nextStudentId},
      m_firstName {firstName},
      m_lastName {lastName} {
    // then increment the next ID.
    m_nextStudentId++;

    // Draw a picture of this in memory.
}


// We don't repeat the static keyword.
int Student::getNextStudentId() {
    // This function is static, so it can use the static m_nextStudentId,
    // but it can't use m_id, m_firstName, or m_lastName, nor can it call non-static
    // functions of this class.
    return m_nextStudentId;
}

bool Student::operator<(const Student &rhs) const {
    return m_id < rhs.m_id;
}

bool Student::operator==(const Student &rhs) const {
    return m_id == rhs.m_id;
}



int Student::getId() const {
    return (*this).m_id;
}

const std::string & Student::getFirstName() const {
    return this->m_firstName;
}
