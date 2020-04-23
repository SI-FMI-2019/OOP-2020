#include "HybridAutomobile.hpp"

HybridAutomobile::HybridAutomobile(const unsigned hp, 
					   			   const char* model, 
					   			   const unsigned year,
					   			   const double price,
								   const unsigned cylinders,
								   const double tankQuantity,
								   const double tankCapacity,
								   const unsigned batteryCapacity,
								   const unsigned batteryPercentage,
								   const bool isEngineElectric)
	: PetrolAutomobile(hp, model, year, price, cylinders, tankQuantity, tankCapacity)
	, ElectricAutomobile(hp, model, year, price, batteryCapacity, batteryPercentage)
	, isEngineElectric(isEngineElectric)
{
}

HybridAutomobile::HybridAutomobile(const HybridAutomobile& other)
	: PetrolAutomobile(other)
	, ElectricAutomobile(other)
	, isEngineElectric(other.isEngineElectric)
{
}

HybridAutomobile& HybridAutomobile::operator=(const HybridAutomobile& other)
{
	if (this != &other)
	{
		PetrolAutomobile::operator=(other);
		ElectricAutomobile::operator=(other);
		this->isEngineElectric = other.isEngineElectric;	
	}
	return *this;
}

void HybridAutomobile::switchEngines()
{
	if (!this->isEngineElectric && this->getTankQuantity() == 0)
	{
		this->isEngineElectric = true;
	}
	else if (this->isEngineElectric && this->getPercentage() == 0)
	{
		this->isEngineElectric = false;
	}
}

bool HybridAutomobile::getIsEngineElectric() const
{
	return this->isEngineElectric;
}