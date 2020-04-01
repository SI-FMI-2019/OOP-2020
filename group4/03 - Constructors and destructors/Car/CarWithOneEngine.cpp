/**
 * Example if we used a static variable of type Engine
 * to initialize a car
 */
#include "Engine.h"
class Car {
   public:
    Engine engine;
};

int main() {
    Car car;
    car.engine = Engine(120, "Engine name");

    Car car1{Engine(500, "Engine 2")};
}
