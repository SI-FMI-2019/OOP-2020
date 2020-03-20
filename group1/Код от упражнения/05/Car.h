#ifndef CPP_CAR_H
#define CPP_CAR_H

#include "SteeringWheel.h"

class Car {
public:
    Car();
    Car(SteeringWheel* wheel);
    void drive_the_car(const double& angle);
private:
    int horsepower;
    SteeringWheel* wheel;
};


#endif //CPP_CAR_H
