#include "Car.hpp"
#include <iostream>

Car::Car()
    : Vehicle()
    , seats(1)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Car::Car(const char* model, const char* plate, const double& fuel, const unsigned& seats)
    : Vehicle(model, plate, fuel)
    , seats(seats)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Car::Car(const Car& other)
    : Vehicle(other)
    , seats(other.seats)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Car& Car::operator=(const Car& other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this != &other)
    {
        Vehicle::operator=(other);
        this->seats = other.seats;
    }

    return *this;
}

Car::~Car()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Car::print() const
{
    std::cout << "Car: ";
    Vehicle::print();
    std::cout << this->seats << std::endl;
}

unsigned Car::getSeats() const 
{
    return this->seats;
}