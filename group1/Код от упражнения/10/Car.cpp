//
// Created by lyubo on 19.03.20 г..
//

#include "Car.h"

void Car::print() const
{
    std::cout << "Maker: " << this->Vehicle::get_maker() << std::endl;
    std::cout << "Model: " << this->model << std::endl;
    std::cout << "Horsepower: " << this->horsepower << std::endl;
    std::cout << "Seats: " << this->seats << std::endl;
}

MyString Car::get_engine() const {
    return this->engine_type;
}