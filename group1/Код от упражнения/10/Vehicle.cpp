//
// Created by lyubo on 29.04.20 г..
//

#include "Vehicle.h"
#include "MyString.h"

MyString Vehicle::get_maker() const {
    return this->maker;
}

MyString Vehicle::get_model() const {
    return this->model;
}

int Vehicle::get_horsepower() const {
    return this->horsepower;
}


