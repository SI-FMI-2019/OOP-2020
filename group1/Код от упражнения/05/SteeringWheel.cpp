//
// Created by lyubo on 19.03.20 г..
//

#include "SteeringWheel.h"

void SteeringWheel::steer(const double &angle) {
    std::cout << "Steering the car";
    this->deg = angle;
}