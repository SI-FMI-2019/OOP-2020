#include "Complex.hpp"

int main()
{
    Complex z;
    z.makeComplex(3, 4);

    Complex z1;
    z1.makeComplex(2, 8);

    // z.addComplex(z1);
    z.productComplex(z1);
    z.print();
    return 0;
}