#ifndef CPP_CAR_H
#define CPP_CAR_H

#include "Vehicle.h"
#include "MyString.h"

class Car: public Vehicle
{
private:
    MyString engine_type;
    int seats;
public:
    Car():seats(0), engine_type("") {}
    Car(const char* maker, const char* model, const int& horsepower, const int& seats, const char* engine):
        Vehicle(maker, model, horsepower), seats(seats), engine_type(engine) {}
    Car(const char* maker, const char* model, const int& horsepower, const int& seats, const MyString& engine):
        Vehicle(maker, model, horsepower), seats(seats), engine_type(engine) {}
        MyString get_engine() const;

    void print() const override;
};
#endif //CPP_CAR_H
