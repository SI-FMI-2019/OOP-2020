#include <iostream>
#include <vector>

class Car {
   public:
    int carNumber = 2;

    virtual void print() const {
        std::cout << "Car\n";
    }

    virtual Car* clone() const {
        return new Car(*this); // Call the copy constructor
    };

    // All classes which inherit this one will have virtual destructors
    // Just for good measure
    virtual ~Car(){};
};

class Fiat : public Car {
   public:
    int fiatNumber = 7;

    virtual void print() const override {
        std::cout << "Fiat\n";
    }

    Car* clone() const {
        return new Fiat(*this);
    };
};

class Peugeot : public Car {
   public:
    int peugeotNumber = 14;

    virtual void print() const override {
        std::cout << "Peugeot\n";
    }

    Car* clone() const {
        return new Peugeot(*this);
    };
};

class PolymorphicContainer {
private:
    Car** cars = nullptr;
    int size = 0;
public:
    PolymorphicContainer() { }

    PolymorphicContainer(const PolymorphicContainer& rhs) {
        this->cars = new Car*[rhs.size];
        for (int i = 0; i < this->size; i++) {
            this->cars[i] = rhs.cars[i]->clone();
        }
    }

    PolymorphicContainer& operator=(const PolymorphicContainer& rhs) {
        if (this != &rhs) {
            // Free memory like destructor
            for (int i = 0; i < this->size; i++) {
                delete this->cars[i];
            }
            delete[] this->cars;

            // Copy memory like copy constructor
            this->cars = new Car*[rhs.size];
            for (int i = 0; i < this->size; i++) {
                this->cars[i] = rhs.cars[i]->clone();
            }
        }
        return *this;
    }

    ~PolymorphicContainer() {
        // VERY IMPORTANT to use custom destructor
        for (int i = 0; i < this->size; i++) {
            delete this->cars[i];
        }
        delete[] this->cars;
    }

    void add(Car* car) {
        Car** newCars = new Car*[this->size + 1];
        // No need to delete pointers like operator=, only redirect them
        for (int i = 0; i < this->size; i++) {
            newCars[i] = this->cars[i];
        }
        newCars[this->size] = car;

        delete[] this->cars;
        this->cars = newCars;
        this->size += 1;
    }

    int getSize() {
        return this->size;
    }

    Car* at(int index) const {
        if (0 <= index && index < this->size) {
            return this->cars[index];
        }
        return nullptr;
    }
};

class PolymorphicVector : protected std::vector<Car*> {
public:
    void push_back(Car* car) {
        vector::push_back(car);
    }

    PolymorphicVector() = default; // Nothing special to do here

    PolymorphicVector(const PolymorphicVector& rhs) {
        // Copy the pointers by making clones
        for (int i = 0; i < rhs.size(); i++) {
            this->push_back(rhs.at(i)->clone());
        }
    }

    PolymorphicVector& operator=(const PolymorphicVector& rhs) {
        if (this != &rhs) {
            // Destructor logic
            for (int i = 0; i < this->size(); i++) {
                delete this->at(i);
            }

            // Remove the old pointers from the vector (set size to 0)
            vector::clear();

            // Copy constructor logic
            for (int i = 0; i < rhs.size(); i++) {
                this->push_back(rhs.at(i)->clone());
            }
        }
        return *this;
    }

    ~PolymorphicVector() {
        // VERY IMPORTANT to use custom destructor
        for (int i = 0; i < this->size(); i++) {
            delete this->at(i);
        }
    }

    int size() const {
        return vector::size();
    }

    Car* at(int index) const {
        return vector::at(index);
    }
};

int main() {
    PolymorphicContainer container;
    container.add(new Car());
    container.add(new Fiat());
    for (int i = 0; i < container.getSize(); i++) {
        Car* car = container.at(i);
        if (car) {
            car->print();
        }
    }

    PolymorphicVector vector;
    vector.push_back(new Peugeot());
    Fiat fiat;
    vector.push_back(fiat.clone());

    for (int i = 0; i < vector.size(); i++) {
        Car* car = vector.at(i);
        if (car) {
            car->print();
        }
    }
}
