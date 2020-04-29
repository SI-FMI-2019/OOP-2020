//
// Created by lyubo on 29.04.20 г..
//

#ifndef CPP_VEHICLE_H
#define CPP_VEHICLE_H

#include "MyString.h"

class Vehicle
{
public:
    Vehicle(): horsepower(0), maker(""), model("") {}
    Vehicle(const char* maker, const char* model, const int& horsepower): maker(maker), model(model), horsepower(horsepower){}
    Vehicle(const MyString& maker, const MyString& model, const int& horsepower): maker(maker), model(model), horsepower(horsepower){}

    MyString get_maker() const;
    MyString get_model() const;
    int get_horsepower() const;
    virtual void print() const = 0;

protected:
    MyString maker;
    MyString model;
    int horsepower;
};


#endif //CPP_VEHICLE_H
