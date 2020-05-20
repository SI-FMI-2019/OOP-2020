#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
   public:
    virtual void drive() const {
        std::cout << "I'm driving my " << getName() << "\n";
    }
    virtual string getName() const = 0;
    virtual ~Car() {};
};

class Fiat : private Car {
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
    // Changing the expected behaviour is a bad idea
    void drive() const {
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += i;
        }
        std::cout << "Sum from 1 to 100 = " << sum << "\n";
    }
};

void drive(Fiat fiat) {
    std::cout << "I'm driving my " << fiat.getName() << "\n";
}

int main() {
    Fiat fiat;
    // fiat.drive(); // Fiat inherits Car privately and I can't use drive(), 200 IQ boiz
    drive(fiat);

    Peugeot peugeot;
    peugeot.drive();
}
