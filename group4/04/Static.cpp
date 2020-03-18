#include "Static.h"

#include <iostream>

Static::Static() {
    static int constructorCalls = 0;
    constructorCalls++;
    std::cout << "Constructor called: ";
    std::cout << constructorCalls << "\n";
}

int Static::generateId() const {
    static int staticId = 0;
    int newId = staticId * secretNumber;
    staticId++;
    return newId;
}

char Static::letter = 'a';

int main() {
    // Example a;
    // std::cout << a.generateId() << "\n";
    // std::cout << a.generateId() << "\n";
    // std::cout << a.generateId() << "\n";

    // a.letter = 'Z';
    // std::cout << a.letter << "\n";
    // Example b;
    // std::cout << b.letter << "\n";
}
