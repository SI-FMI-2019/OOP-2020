#ifndef LAPTOP_HPP
#define LAPTOP_HPP

#include <cstddef>
#include "Processor.hpp"

class Laptop
{
public:
    Laptop();
    Laptop(const char*, const double&);     // create Laptop by name and price
    Laptop(const char*, 
           const double&, 
           const double&, 
           const Processor&, 
           const double&, 
           const size_t&);
    Laptop(const Laptop&);
    Laptop& operator=(const Laptop&);
    ~Laptop();

    // methods of the class Laptop::operator==(const Laptop&)
    bool operator==(const Laptop&);
    bool operator!=(const Laptop&);
    bool operator<(const Laptop&);
    bool operator>(const Laptop&);

    // no longer methods of this class -> functions
    friend bool operator==(const Laptop&, const Laptop&);
    friend bool operator!=(const Laptop&, const Laptop&);
    friend bool operator<(const Laptop&, const Laptop&);
    friend bool operator>(const Laptop&, const Laptop&);

    void printLaptopInformation() const;
private:
    char* brandAndModel;
    double price;
    double screenInches;
    Processor processor;
    double ram;
    size_t batteryCapacity;                 // mAh

    void copyFrom(const Laptop&);
    void deallocateMemory();
};

#endif  // LAPTOP_HPP