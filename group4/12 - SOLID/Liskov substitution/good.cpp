#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
   public:
    void drive() const {
        std::cout << "I'm driving my " << getName() << "\n";
    }
    virtual string getName() const = 0;
    virtual ~Car(){};
};

class Fiat : public Car {
   public:
    virtual string getName() const override {
        return "Fiat";
    }
};

class Peugeot : public Car {
   public:
    virtual string getName() const override {
        return "Peugeot";
    }
};

int main() {
    Fiat fiat;
    fiat.drive();

    Car* peugeot = new Peugeot();
    peugeot->drive();
}
