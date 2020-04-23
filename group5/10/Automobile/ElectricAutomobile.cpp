#include "ElectricAutomobile.hpp"
#include <iostream>

ElectricAutomobile::ElectricAutomobile(const unsigned hp, 
					   			   	   const char* model, 
					   			   	   const unsigned year,
					   			       const double price,
								   	   const unsigned batteryCapacity,
								   	   const unsigned batteryPercentage)
	: Automobile(hp, model, year, price)
	, batteryCapacity(batteryCapacity)
	, batteryPercentage(batteryPercentage)
{
}

ElectricAutomobile::ElectricAutomobile(const ElectricAutomobile& other)
	: Automobile(other)
	, batteryCapacity(batteryCapacity)
	, batteryPercentage(batteryPercentage)
{
}

ElectricAutomobile& ElectricAutomobile::operator=(const ElectricAutomobile& other)
{
	if (this != &other)
	{
		Automobile::operator=(other);
		this->batteryCapacity = other.batteryCapacity;
		this->batteryPercentage = other.batteryPercentage;
	}
	return *this;
}

void ElectricAutomobile::charge(const unsigned percentage)
{
	if (percentage >= 0 && percentage <= 100)
	{
		this->batteryPercentage = percentage;
	}
	else
	{
		std::cout << "Invalid percentage level" << std::endl;
	}
}

unsigned ElectricAutomobile::getPercentage() const
{
	return this->batteryPercentage;
}