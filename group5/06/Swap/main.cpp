#include <iostream>

#include "Complex.hpp"
#include "main.hpp"

int main()
{
    int a = 5;
    int b = 10;
    myswap<int>(a, b); 

    double x = 8.4;
    double y = 6.3;

    myswap<double>(x, y);

    Complex z1(3, 4);
    Complex z2(2, 9);

    myswap<Complex>(z1, z2);

    z1.print();
    z2.print();

    // std::cout << a << " " << b << std::endl;
    // std::cout << x << " " << y << std::endl;
    return 0;
}