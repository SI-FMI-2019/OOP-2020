#include <iostream>
#include "Cup.hpp"

unsigned Cup::nextId = 0;

Cup::Cup()
    : quantity(0)
    , capacity(250)
    , color(RED)
    , id(++nextId)
{
    std::cout << "Cup(), id: " << this->id << std::endl;
}

Cup::Cup(double quantity, double capacity, Color color)
    : quantity(quantity)
    , capacity(capacity)
    , color(color)
    , id(++nextId)
{
    std::cout << "Cup(double, double, color), id: " << this->id << std::endl;
}

Cup::Cup(const Cup& other)
    : quantity(other.quantity)
    , capacity(other.capacity)
    , color(other.color)
    , id(++nextId)
{
    std::cout << "Cup(const Cup&), id: " << this->id << std::endl;
}

Cup::~Cup()
{
    std::cout << "~Cup(), id: " << this->id << std::endl;
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