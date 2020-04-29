//
// Created by lyubo on 29.04.20 г..
//

#ifndef CPP_MOTORCYCLE_H
#define CPP_MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle: public Vehicle
{
public:
    Motorcycle(): luggage_capacity(0) {}
    Motorcycle(const char* maker, const char* model, const int& horsepower, const int& luggage): Vehicle(maker, model, horsepower), luggage_capacity(luggage){}

    void print() const override;
private:
    int luggage_capacity;
};

#endif //CPP_MOTORCYCLE_H
