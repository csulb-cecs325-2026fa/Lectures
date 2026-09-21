//
// Created by neald on 2/27/2025.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <ostream>

// OLD STUFF: this should be review.
class Complex {
    // Fields. If otherwise not provided, m_real and m_imaginary will be set to 0.
    double m_real {};
    double m_imaginary {};

public:
    // CONSTRUCTORS.
    // A Complex can be constructed with no parameters. The default behavior will initialize all the fields
    // with their own defaults.
    Complex() = default;


    // A Complex can also be constructed with two parameters, which we will use to initialize the fields.
    Complex(double real, double imaginary);

    // Every class secretly comes with a "Copy constructor". It is used to construct a new value using an
    // existing object to copy.
    Complex(const Complex& other) = default;
    // This line isn't needed, the compiler generates it automatically.
    // The default copy constructor copies each field from "other" to the new object.

    // Take a look at the implementation of the constructor in Complex.cpp.
    // Then look at main.cpp to see examples of constructing Complex objects.


    // METHODS:
    // Mutators. Simple.
    void setReal(double real);
    void setImaginary(double imaginary);

    // Accessors.
    // This accessor is flawed; see the main().
    double getImaginary() const;





    // To promise that a method won't mutate the object it's called on, we add the "const"
    // keyword after the parameter list.
    double getReal() const;
    // This "const method" CANNOT make mutating changes to the object's fields. To do so would
    // be a compile-time semantic error.
    // getReal() can thus be called on a const object.



    // Next, operators. C++ lets us provide operators for our classes, letting us write very expressive
    // code using symbols that are well understood.

    // operator+: this function will get called when the compiler sees "x + y", where x is a Complex object, and y
    // matches the type of the "rhs" parameter to the operator.
    // It's up to us to determine the return type. Ask yourself: if we add two complex numbers, what do we get back?
    // Another Complex!
    Complex operator+(const Complex& rhs) const;










    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;

    // This operator can't be part of the Complex class, because the LHS is not a Complex object, it is an ostream
    // object. But we still want it to access the private fields of a Complex so we can print the real and imaginary
    // values. The "friend" keyword declares a *GLOBAL* function that has access to the private fields of this class.
    friend std::ostream& operator<<(std::ostream& lhs, const Complex& rhs);


    // A convenient static value to represent "i", e.g., the Complex {0, 1} == 0 + 1i.
    const static Complex I;


    // Self-mutating operators.
    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);




    bool operator<(const Complex& rhs) const;

    bool operator==(const Complex& rhs) const;






};


#endif //COMPLEX_H
