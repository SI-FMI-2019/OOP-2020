#include "House.hpp"

House::House(const char* address,
            const unsigned floors, 
            const char* date,
            const double price,
            const unsigned furnitureLevel,
            const bool hasGarage)
    : Building(address, floors, date, price)
    , furnitureLevel(furnitureLevel)
    , hasGarage(hasGarage)
{
}

unsigned House::getFurnitureLevel() const
{
    return this->furnitureLevel;
}

bool House::getHasGarage() const
{
    return this->hasGarage;
}

std::ostream& operator<<(std::ostream& os, const House& house)
{
    os << "House\n";
    os << house.address << "\n";
    os << house.floors << "\n";
    os << house.date << "\n";
    os << house.price << "\n";
    os << house.furnitureLevel << "\n";
    os << house.hasGarage << "\n";

    return os;
}