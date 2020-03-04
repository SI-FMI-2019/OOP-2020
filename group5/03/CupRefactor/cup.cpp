#include <iostream>
#include "cup.hpp"

Cup::Cup()
    : quantity(0)
    , capacity(250)
    , color(RED)
{
    std::cout << "Cup()" << std::endl;
}

Cup::Cup(double quantity, double capacity, Color color)
    : quantity(quantity)
    , capacity(capacity)
    , color(color)
{
    std::cout << "Cup(double, double, color)" << std::endl;
}

Cup::Cup(const Cup& other)
    : quantity(other.quantity)
    , capacity(other.capacity)
    , color(other.color)
{
    std::cout << "Cup(const Cup&)" << std::endl;
}

Cup::~Cup()
{
    std::cout << "~Cup()" << std::endl;
}

void Cup::fill(const double quantity)
{
    if (this->capacity < this->quantity + quantity)
    {
        std::cout << "The cup is gonna overflow. Stop now!" << std::endl;
        return;
    }

    this->quantity += quantity;
}

double Cup::getQuantity() const
{
    return this->quantity;
}