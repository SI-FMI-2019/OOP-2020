#include "Vehicle.hpp"

#include <cstring>
#include <iostream>

Vehicle::Vehicle()
    : model(new char [8])
    , registrationPlate(new char [8])
    , fuelLiters(0)
{
    const char* DEFAULT = "Default";
    strncpy(this->model, DEFAULT, strlen(DEFAULT));
    strncpy(this->registrationPlate, DEFAULT, strlen(DEFAULT));

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Vehicle::Vehicle(const char* model, const char* plate, const double& fuel)
    : model(new char [strlen(model) + 1])
    , registrationPlate(new char [strlen(plate) + 1])
    , fuelLiters(fuel)
{
    strncpy(this->model, model, strlen(model));
    strncpy(this->registrationPlate, plate, strlen(plate));
    this->model[strlen(this->model)] = '\0';
    this->registrationPlate[strlen(this->registrationPlate)] = '\0';

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Vehicle::copyFrom(const Vehicle& other)
{
    this->model = new char [strlen(other.model) + 1];
    strncpy(this->model, other.model, strlen(other.model));
    this->model[strlen(this->model)] = '\0';

    this->registrationPlate = new char [strlen(other.registrationPlate) + 1];
    strncpy(this->registrationPlate, other.registrationPlate, 
                                        strlen(other.registrationPlate));
    this->registrationPlate[strlen(this->registrationPlate)] = '\0';

    this->fuelLiters = other.fuelLiters;
}

Vehicle::Vehicle(const Vehicle& other)
{
    copyFrom(other);

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this != &other)
    {
        delete[] this->model;
        delete[] this->registrationPlate;

        copyFrom(other);
    }
    
    return *this;
}

Vehicle::~Vehicle()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    delete[] this->model;
    delete[] this->registrationPlate;
}

void Vehicle::print() const
{
    std::cout << "Vehicle: " << this->model << std::endl;
    std::cout << this->registrationPlate << std::endl;
    std::cout << this->fuelLiters << std::endl;
}

void Vehicle::fuel(const double& liters)
{
    this->fuelLiters += liters;
}