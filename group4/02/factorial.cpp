#include "factorial.hpp"

int Factorial::factorial(int p) {
    if (p == 0) {
        return 1;
    } else {
        return factorial(p - 1) * p;
    }
}

void Factorial::calc(int fact) {
    if (fact < 0) {
        fact = 0;
    }
    this->fact = fact;
    this->calculated = this->factorial(fact);
}

int Factorial::getCalculated() const {
    return this->calculated;
}

int Factorial::getFact() const {
    return this->fact;
}

Factorial::Factorial() {
    fact = 0;
    calculated = 1;
}

Factorial::Factorial(int f) {
    fact = f;
    calculated = factorial(f);
}
