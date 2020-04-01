#pragma once
#include "Engine.hpp"

class Car {
   private:
    int tires = 4;  // Accessible only via the friend function
    Engine engine;

   public:
    Car() : engine(12) {
    }
    int getPower() {
        return engine.power;  // Made possible by being a friend class
    }

    int getEnginePower(Engine engine) {  // Friend method because Car is friend of Engine
        return engine.power;
    }

    friend int getTireCount(const Car&);  // Has access to private fields of Car
};
