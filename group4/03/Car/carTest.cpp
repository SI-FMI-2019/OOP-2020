#include "Car.h"
#include "Engine.h"

int main() {
    Car car;
    Engine engine1 = Engine(120, "er12");
    car.addEngine(engine1);
    // car.addEngine(Engine(120, "engine 2"));
}
