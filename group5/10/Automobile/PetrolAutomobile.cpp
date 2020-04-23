#include "PetrolAutomobile.hpp"
#include <iostream>

PetrolAutomobile::PetrolAutomobile(const unsigned hp, 
					   			   const char* model, 
					   			   const unsigned year,
					   			   const double price,
								   const unsigned cylinders,
								   const double tankQuantity,
								   const double tankCapacity)
	: Automobile(hp, model, year, price)
	, cylinders(cylinders)
	, tankQuantity(tankQuantity)
	, tankCapacity(tankCapacity)
{
}

PetrolAutomobile::PetrolAutomobile(const PetrolAutomobile& other)
	: Automobile(other)
	, cylinders(other.cylinders)
	, tankQuantity(other.tankQuantity)
	, tankCapacity(other.tankCapacity)
{
}

PetrolAutomobile& PetrolAutomobile::operator=(const PetrolAutomobile& other)
{
	if (this != &other)
	{
		Automobile::operator=(other);
		this->cylinders = other.cylinders;
		this->tankQuantity = other.tankQuantity;
		this->tankCapacity = other.tankCapacity;
	}
	return *this;
}

void PetrolAutomobile::fuel(const double litres)
{
	if (this->tankQuantity + litres <= this->tankCapacity)
	{
		this->tankQuantity += litres;
	}
	else
	{
		std::cout << "Not enough capacity" << std::endl;
	}
}

double PetrolAutomobile::getTankQuantity() const
{
	return this->tankQuantity;
}