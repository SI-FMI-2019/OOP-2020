#include "Building.hpp"

#include <cstring>

Building::Building(const char* address,
                   const unsigned floors,
                   const char* date,
                   const double price)
    : address(new char [strlen(address) + 1])
    , floors(floors)
    , date(new char[strlen(date) + 1])
    , price(price)
{
    strncpy(this->address, address, strlen(address));
    strncpy(this->date, date, strlen(date));

    this->address[strlen(this->address)] = '\0';
    this->date[strlen(this->date)] = '\0';
}

Building::Building()
    : Building("undefined", 0, "00.00.0000", 0)
{
}

Building::Building(const Building& other)
    : Building(other.address, other.floors, other.date, other.price)
{
}

Building& Building::operator=(const Building& other)
{
    if (this != &other)
    {
        delete[] this->address;
        delete[] this->date;

        this->address = new char [strlen(other.address) + 1];
        this->date = new char [strlen(other.date) + 1];

        strncpy(this->address, other.address, strlen(address));
        strncpy(this->date, other.date, strlen(date));

        this->address[strlen(this->address)] = '\0';
        this->date[strlen(this->date)] = '\0';

        this->floors = other.floors;
        this->price = other.price;
    }
    return *this;
}

Building::~Building()
{
    delete[] this->address;
    delete[] this->date;
}

void Building::setPrice(const double newPrice)
{
    this->price = newPrice;
}

const char* Building::getAddress() const
{
    return this->address;
}

std::ostream& operator<<(std::ostream& os, const Building& building)
{
    os << "Building\n";
    os << building.address << "\n";
    os << building.floors << "\n";
    os << building.date << "\n";
    os << building.price << "\n";

    return os;
}