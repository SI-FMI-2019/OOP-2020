#include <iostream>

class Engine {
   private:
    int power = 120;

    friend class Car;  // Car has access to the private fields/methods of Engine
};

class Car {
   private:
    int tires = 4;  // Accessible only via the friend function
    Engine engine;

   public:
    int getPower() {
        return engine.power;  // Made possible by being a friend class
    }

    int getEnginePower(Engine engine) {  // Friend method because Car is friend of Engine
        return engine.power;
    }

    friend int getTireCount(const Car&);  // Has access to private fields of Car
};

int getTireCount(const Car& car) {
    std::cout << car.tires;
}