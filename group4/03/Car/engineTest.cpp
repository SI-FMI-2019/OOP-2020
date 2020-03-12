#include "Engine.h"

int main() {
    // Constructor
    Engine e1(123, "er12");
    // Copy constructor
    Engine e2 = e1;  // == Engine e2(e1);
    // Setter
    e2.setName("qwerty");
    // Operator=
    e1 = e2 = e1;

    // Call constructor 5 times
    Engine* p = new Engine[5];
    // Call destructor 5 times
    delete[] p;

    std::cout << "e1 = " << e1.getName() << " e2 = " << e2.getName() << "\n";
    // When we reach } the destructors are called
}
