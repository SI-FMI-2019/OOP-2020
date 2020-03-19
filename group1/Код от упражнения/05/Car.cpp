//
// Created by lyubo on 19.03.20 г..
//

#include "Car.h"

Car::Car() = default;
Car::Car(SteeringWheel *wheel) {
    this->wheel = wheel;
}

void Car::drive_the_car(const double& angle) {
    this->wheel->steer(angle);
}