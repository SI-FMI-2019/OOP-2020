#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>

class Building
{
public:
    Building();
    Building(const char*, 
             const unsigned, 
             const char*,
             const double);
    Building(const Building&);
    Building& operator=(const Building&);
    ~Building();

    void setPrice(const double);
    const char* getAddress() const;

    friend std::ostream& operator<<(std::ostream& os, const Building&);

protected:
    char* address;
    unsigned floors;
    char* date;
    double price;
};

#endif// !BUILDING_HPP