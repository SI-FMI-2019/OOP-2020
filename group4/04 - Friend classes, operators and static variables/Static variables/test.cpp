#include <iostream>
#include "Static.h"

int main() {
    Static a;
    std::cout << a.generateId() << "\n";
    std::cout << a.generateId() << "\n";
    std::cout << a.generateId() << "\n";
}
