#include <iostream>
#include "cup.hpp"

void Cup::setQuantity(const double quantiry)
{
    this->quantity = quantity;
}

void Cup::setCapacity(const double capacity)
{
    this->capacity = capacity;
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

void Cup::setColor(const Color& color)
{
    this->color = color;
}

double Cup::getQuantity() const
{
    return this->quantity;
}