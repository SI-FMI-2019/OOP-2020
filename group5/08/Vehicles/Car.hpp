#ifndef CAR_HPP
#define CAR_HPP

#include "Vehicle.hpp"

class Car : public Vehicle
{
public:
    Car();
    Car(const char*, const char*, const double&, const unsigned& seats);
    Car(const Car&);
    Car& operator=(const Car&);
    ~Car();
    unsigned getSeats() const;
    void print() const;
private:
    unsigned seats;
};

#endif // CAR_HPP