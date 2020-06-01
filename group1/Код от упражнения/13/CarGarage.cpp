#include <iostream>
#include <vector>
#include <string>
#include "Car.h"
#include "Motorcycle.h"
#include "Vehicle.h"

class CarGarage{
public:
    CarGarage():size(1), capacity(0)
    {
        this->vehicles = CarGarage::alloc_memory(size);
    }
    CarGarage(const CarGarage& from): size(from.size), capacity(from.capacity)
    {
        this->vehicles = CarGarage::alloc_memory(this->size);
        CarGarage::copy_memory(this->vehicles, from.vehicles, this->capacity);
    }

    CarGarage& operator=(const CarGarage& from)
    {
        if(this != &from)
        {
            CarGarage::clear_memory(this->vehicles, this->capacity);
            this->vehicles = CarGarage::alloc_memory(this->size);
            CarGarage::copy_memory(this->vehicles, from.vehicles, this->capacity);
        }
        return *this;
    }

    ~CarGarage()
    {
        CarGarage::clear_memory(this->vehicles, this->capacity);
    }

    void add_car(const Car& some_car)
    {
        if(this->capacity == this->size)
        {
            this->size *= 2;
            Vehicle** bigger_garage = CarGarage::alloc_memory(this->size);
            CarGarage::copy_memory(bigger_garage, this->vehicles, this->capacity);
            CarGarage::clear_memory(this->vehicles, this->capacity);

            this->vehicles = bigger_garage;
        }

        this->vehicles[this->capacity] = new Car(some_car);
        this->capacity += 1;
    }

    void add_motorcycle(const Motorcycle& some_motorcycle)
    {
        if(this->capacity == this->size)
        {
            this->size *= 2;
            Vehicle** bigger_garage = CarGarage::alloc_memory(this->size);
            CarGarage::copy_memory(bigger_garage, this->vehicles, this->capacity);
            CarGarage::clear_memory(this->vehicles, this->capacity);

            this->vehicles = bigger_garage;
        }

        this->vehicles[this->capacity] = new Motorcycle(some_motorcycle);
        this->capacity += 1;
    }
private:
    Vehicle** vehicles;
    unsigned size;
    unsigned capacity;

    static Vehicle** alloc_memory(const unsigned& size)
    {
        return new Vehicle*[size];
    }

    static void copy_memory(Vehicle** source, Vehicle** destination, const unsigned& capacity)
    {
        for(int i = 0; i < capacity; i++)
        {
            auto* is_vehicle_car = dynamic_cast<Car*>(source[i]);

            if(is_vehicle_car != nullptr)
            {
                destination[i] = new Car(*is_vehicle_car);
            }
            else
            {
                auto* vehicle_as_motorcycle = dynamic_cast<Motorcycle*>(source[i]);
                destination[i] = new Motorcycle(*vehicle_as_motorcycle);
            }
        }
    }

    static void clear_memory(Vehicle** memory, const unsigned& size)
    {
        for(int i = 0; i < size; i++)
        {
            delete memory[i];
        }
        delete[] memory;
    }
};
int main(){

    Car my_car("Mazda", "6", 120, 5, "I4");
    Motorcycle my_motorcycle("Honda", "RX250", 50, 12);

    return 0;
}