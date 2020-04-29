//
// Created by lyubo on 29.04.20 г..
//

#include "Motorcycle.h"

void Motorcycle::print() const
{
    std::cout << "Maker: " << this->maker << std::endl;
    std::cout << "Model: " << this->model << std::endl;
    std::cout << "Horsepower: " << this->horsepower << std::endl;
    std::cout << "Luggage capacity: " << this->luggage_capacity << std::endl;
}