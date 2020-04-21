#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Building.hpp"

class House : public Building
{
public:
    House(const char*, 
          const unsigned, 
          const char*,
          const double,
          const unsigned,
          const bool);

    unsigned getFurnitureLevel() const;
    bool getHasGarage() const;

    friend std::ostream& operator<<(std::ostream& os, const House&);
private:
   unsigned furnitureLevel;
   bool hasGarage; 
};

#endif // !HOUSE_HPP