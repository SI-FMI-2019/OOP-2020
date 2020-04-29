#ifndef PETROLAUTOMOBILE_HPP
#define PETROLAUTOMOBILE_HPP

#include "Automobile.hpp"

class PetrolAutomobile : virtual public Automobile
{
public:
	PetrolAutomobile() = default;
	PetrolAutomobile(const unsigned, 
					 const char*, 
					 const unsigned, 
					 const double,
					 const unsigned,
					 const double,
					 const double);
	PetrolAutomobile(const PetrolAutomobile&);
	PetrolAutomobile& operator=(const PetrolAutomobile&);
	~PetrolAutomobile() = default;

	void fuel(const double litres);
	double getTankQuantity() const;
private:
	unsigned cylinders;
	double tankQuantity;
	double tankCapacity;
};

#endif // !PETROLAUTOMOBILE_HPP
