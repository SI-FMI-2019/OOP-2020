#include <iostream>

class Car {
public:
    int carNumber = 2;

    virtual void print() const {
        std::cout << "Car\n";
    }

    // All classes which inherit this one will have virtual destructors
    // Just for good measure
    virtual ~Car() {};
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

    virtual void print() const override {
        std::cout << "Peugeot\n";
    }
};

int main() {
    /* Static cast */
    {
        Fiat fiat;

        // C-like casting
        ((Car)fiat).print(); // prints Car
        // Modern C++ static casting
        static_cast<Car>(fiat).print(); // prints Car
        // (Car) and static_cast<Car> do the same thing
    }

    /* Dynamic cast */
    {
        Car *fiat = new Fiat();
        fiat->print(); // prints Fiat
        std::cout << fiat->carNumber << "\n"; // prints 2
        // std::cout << fiat->fiatNumber; // INACCESSIBLE

        // Successful dynamic cast
        Fiat* fiatPtr = dynamic_cast<Fiat*>(fiat); // returns nullptr on fail
        if (fiatPtr) { // Check cast was successful (not nullptr)
            std::cout << fiatPtr->fiatNumber << "\n"; // Outputs 7 properly
        } else {
            // We never enter this block, because the cast is successful
            std::cout << "Pointer is not of type Fiat\n";
        }

        // Failed dynamic cast
        Peugeot* peugeotPtr = dynamic_cast<Peugeot*>(fiat); // returns nullptr on fail
        if (peugeotPtr) { // Check if cast was successful (not nullptr)
            // We never enter this block because the cast is unsuccessful
            std::cout << peugeotPtr->peugeotNumber << "\n";
        } else {
            std::cout << "Object is not of type Peugeot\n";
        }

        delete fiat;
    }

    /* Static vs Dynamic cast */
    {
        Car* fiat = new Fiat();

        // If you know the type static_cast is ok
        Fiat* staticFiatPtr = static_cast<Fiat*>(fiat); // OK

        // If you don't know the type you have a problem, but the compiler won't complain
        // Which makes it very dangerous!
        Peugeot* staticPeugeotPtr = static_cast<Peugeot*>(fiat); // Undefined behaviour
        // std::cout << staticPeugeotPtr->peugeotNumber; // Very likely segfault
    }
}
