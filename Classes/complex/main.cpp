#include <iostream>
#include "Complex.h"
int main() {
    Complex a {}; // Calls the parameter-less "default" constructor. a = 0 + 0i.
    Complex b {1, 2}; // Calls the two-double constructor. b = 1 + 2i.
    Complex c {b}; // Calls the copy constructor. c = 1 + 2i.
    Complex &r {b}; // r is a reference to b.

    r.setReal(100);

    Complex arr[3] {}; // each Complex object is default-constructed.

    std::cout << b.getReal() << std::endl;
    std::cout << b.getImaginary() << std::endl;
    // These work great!

    const Complex d {0, 1}; // d = 1i
    // d.setReal(10);
    // This next line... doesn't work... ?!?
    std::cout << d.getImaginary() << std::endl;
    // Because d is *const*, the compiler is VERY careful about what methods we can call on it. After all,
    // one of those methods could mutate the object, like setReal() or setImaginary(). How can the compiler
    // know if getImaginary() might mutate the object?
    // We must PROMISE not to mutate the object when getImaginary() is called.
    std::cout << d.getReal() << std::endl;

    // It would be great if we could add complex numbers using the + operator...
    Complex e {b + c};
    Complex g {d * d};
    // Demonstrate the overloaded operator<<
    std::cout << g << std::endl;


    // Demonstrate the self-mutating operators.
    (g += e) += e;
    std::cout << g << std::endl;
    std::cout << (g += e) + Complex::I << " --- " << g << std::endl;

    return 0;
}
