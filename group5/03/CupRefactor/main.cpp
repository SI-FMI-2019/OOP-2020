#include "cup.hpp"
#include <iostream>

// Function overloading
void f()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void f(int a)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    Cup myCup;

    Cup other(75, 125, WHITE);
    Cup z = other;                              // Copy constructor

    std::cout << z.getQuantity() << std::endl;
    myCup.fill(12);

    int b = 8;
    f();
    f(b);

    double temperature = 37.5;                  // ???
    myCup.fill(temperature);                    // Not cool bro (literally) :)
    
    return 0;
}