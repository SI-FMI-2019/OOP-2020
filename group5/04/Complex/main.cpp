#include "Complex.hpp"

int main()
{
    Complex z(3, 4);

    Complex z1(2, 8);

    z = z + z1;
    z = z * z1;

    bool result = true ? true : false;

    z.print();
    return 0;
}