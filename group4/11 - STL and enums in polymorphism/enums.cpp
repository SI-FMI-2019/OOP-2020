#include <iostream>

enum class CarType {
    Default,
    FIAT,
    PEUGEOT
};

class Car {
protected:
    CarType type;
public:

    Car() {
        type = CarType::Default;
    }

    CarType getType() const {
        return this->type;
    }

    int carNumber = 2;
    virtual void print() const {
        std::cout << "Car\n";
    }
    virtual ~Car() {};
};

class Fiat : public Car {
public:
    Fiat() {
        type = CarType::FIAT;
    }

    int fiatNumber = 7;
    virtual void print() const override {
        std::cout << "Fiat\n";
    }
};

class Peugeot : public Car {
public:
    Peugeot() {
        type = CarType::PEUGEOT;
    }

    int peugeotNumber = 14;
    virtual void print() const override {
        std::cout << "Peugeot\n";
    }
};

int main() {
    Car* ptr = new Fiat();
    if (ptr->getType() == CarType::FIAT) {
        Fiat* fiatPtr = static_cast<Fiat*>(ptr);
        std::cout << fiatPtr->fiatNumber << "\n";
    }
}
