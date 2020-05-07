#include <iostream>

// Abstract class has 1+ pure virtual methods
// We cannot initialize objects from Abstract classes
class Car {
   public:
    int carNumber = 2;

    virtual void print() const = 0; // Purely virtual function(method)

    // All classes which inherit this one will have virtual destructors
    // Just for good measure
    virtual ~Car();
};

class Fiat : public Car {
   public:
    int fiatNumber = 7;

    virtual void print() const override {
        std::cout << "Fiat\n";
    }
};

class Peugeot : public Car {
   public:
    int peugeotNumber = 14;
    // Not overriding print makes this class abstract as well and we
    // cannot make objects of type Peugeot
};

int main() {
    // Car car; // Doesn't compile, Car is abstract
    Fiat fiat; // OK
    // Peugeot peugeot; // Doesn't compile, Peugeot is abstract

    Car* fiatPtr = new Fiat(); // We can still create pointers
    // Car* carPtr = new Car; // Can't make pointers to abstract classes though 
}
