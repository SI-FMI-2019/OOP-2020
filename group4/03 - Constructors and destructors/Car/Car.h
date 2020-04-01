#include "Engine.h"
#pragma once
class Car {
   private:
    Engine* engines;
    int engineCount;
    void copyEngines(int copyCount, Engine* copyEngines);

   public:
    void addEngine(const Engine& engine);
    // The "big 4"
    Car();
    ~Car();
    Car(const Car& rhs);
    Car& operator=(const Car& rhs);
};
