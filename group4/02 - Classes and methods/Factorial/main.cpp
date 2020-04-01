#include <iostream>

#include "factorial.hpp"

// Write a program which calculates Factorial using classes

int main() {
    Factorial p(10);
    p.calc(15);
    Factorial f;
    f.calc(10);
    std::cout << "Factorial from " << p.getFact() << " = ";
    std::cout << p.getCalculated() << "\n";
}
