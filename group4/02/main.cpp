#include <iostream>

#include "factorial.hpp"

int main() {
    Factorial p(10);
    p.calc(15);
    Factorial f;
    f.calc(10);
    std::cout << "Factorial from " << p.getFact() << " = ";
    std::cout << p.getCalculated() << "\n";
}
