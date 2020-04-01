#pragma once
#include <iostream>

class Car;

class Engine {
   private:
    int power = 120;

    Engine(int newPower = 42) {
        std::cout << "Engine Constructor\n";
    }

    Engine& operator=(const Engine& rhs) {
        // Doesn't work as intended
        std::cout << "Engine operator=\n";
        return *this;
    }

    friend class Car;  // Car has access to the private fields/methods of Engine
};
