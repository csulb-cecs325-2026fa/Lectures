//
// Created by neald on 2/27/2025.
//

#include "Complex.h"

#include <cmath>

const Complex Complex::I {0, 1};

Complex::Complex(double real, double imaginary)
    : m_real{real}, m_imaginary{imaginary}
{
}

double Complex::getReal() const {
    return m_real;
}

double Complex::getImaginary() const {
    return m_imaginary;
}

void Complex::setReal(double real) {
    m_real = real;
}

void Complex::setImaginary(double imaginary) {
    m_imaginary = imaginary;
}

Complex Complex::operator+(const Complex &rhs) const {
    Complex temp{m_real + rhs.m_real, m_imaginary + rhs.m_imaginary};
    return temp;
}

Complex Complex::operator-(const Complex &rhs) const {
    Complex temp{m_real - rhs.m_real, m_imaginary - rhs.m_imaginary};
    return temp;
}

Complex Complex::operator*(const Complex &rhs) const {
    // (a + bi) * (c + di) = (a*c + a*d*i + b*c*i - b*d*i*i)
    // == (a*c - b*d) + (a*d + b*c)*i
    Complex temp{
        m_real * rhs.m_real - m_imaginary * rhs.m_imaginary,
        m_real * rhs.m_imaginary + m_imaginary * rhs.m_real
    };
    return temp;
}

std::ostream &operator<<(std::ostream &lhs, const Complex &rhs) {
    // cases:
    // a + 0*i -> a
    // 0 + a*i -> a*i
    // a + b*i -> a + b*i
    // a - b*i -> a - b*i
    if (rhs.m_imaginary == 0) {
        lhs << rhs.m_real;
    } else if (rhs.m_real == 0) {
        lhs << rhs.m_imaginary << 'i';
    } else if (rhs.m_imaginary > 0) {
        lhs << rhs.m_real << " + " << rhs.m_imaginary << 'i';
    } else {
        lhs << rhs.m_real << " - " << -rhs.m_imaginary << 'i';
    }
    return lhs;
}


Complex& Complex::operator+=(const Complex &rhs) {
    this->m_real += rhs.m_real;
    this->m_imaginary += rhs.m_imaginary;
    return *this;
}

Complex & Complex::operator-=(const Complex &rhs) {
    m_real -= rhs.m_real;
    m_imaginary -= rhs.m_imaginary;
    return *this;
}

Complex & Complex::operator*=(const Complex &rhs) {
    m_real = m_real * rhs.m_real - m_imaginary * rhs.m_imaginary;
    m_imaginary = m_real * rhs.m_imaginary + m_imaginary * rhs.m_real;
    return *this;
}

bool Complex::operator<(const Complex &rhs) const {
    double magLhs {sqrt(m_real * m_real + m_imaginary * m_imaginary)};
    double magRhs {sqrt(rhs.m_real * rhs.m_real + rhs.m_imaginary * rhs.m_imaginary)};
    return (magLhs < magRhs);
}

bool Complex::operator==(const Complex &rhs) const {
    return m_real == rhs.m_real && m_imaginary == rhs.m_imaginary;
}
