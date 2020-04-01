#include "Static.h"
#include <iostream>

Static::Static() {
    // Initialized only once when the program starts
    static int constructorCalls = 0;

    constructorCalls++;

    std::cout << "Constructor called: ";
    std::cout << constructorCalls << "\n";
}

int Static::generateId() const {
    // Initialized only once when the program starts
    static int staticId = 0;

    int newId = staticId * secretNumber;
    staticId++;
    return newId;
}

// Initialized only once when the program starts
char Static::letter = 'a';
