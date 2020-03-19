//
// Created by lyubo on 19.03.20 г..
//

#ifndef CPP_STEERINGWHEEL_H
#define CPP_STEERINGWHEEL_H

#include <iostream>
#include "Car.h"

class SteeringWheel {
private:

    void steer(const double& angle);
    double deg;
    int blinkers;

    //friend void Car::drive_the_car(const double &angle);
    friend class Car;
};


#endif //CPP_STEERINGWHEEL_H
