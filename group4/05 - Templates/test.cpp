#include <iostream>
#include "TemplateEncapsulatedDynamicOjbect.hpp"
#include "TemplateSquare.hpp"
#include "TemplateEncapsulatedStaticOjbect.hpp"

int main() {
    double d = 1.1;
    // std::cout << square(d) << "\n";

    EncapsualatedStatic<int> encapsulatedInt;
    encapsulatedInt.set(12);
    // std::cout << encapsulatedInt.get() << "\n";

    EncapsualatedStatic<float> encapsulatedFloat;
    encapsulatedFloat.set(54.42);
    // std::cout << encapsulatedFloat.get() << "\n";

    EncapsulatedDynamic<int> i;
    i.set(12);
    // std::cout << i.get() << "\n";

    EncapsulatedDynamic<char> c;
    c.set('@');
    // std::cout << c.get() << "\n";
}
