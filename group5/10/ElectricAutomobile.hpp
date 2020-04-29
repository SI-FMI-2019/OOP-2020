#ifndef ELECTRICAUTOMOBILE_HPP
#define ELECTRICAUTOMOBILE_HPP

#include "Automobile.hpp"

class ElectricAutomobile : virtual public Automobile
{
public:
	ElectricAutomobile() = default;
	ElectricAutomobile(const unsigned, 
					   const char*, 
					   const unsigned, 
					   const double,
					   const unsigned,
					   const unsigned);
	ElectricAutomobile(const ElectricAutomobile&);
	ElectricAutomobile& operator=(const ElectricAutomobile&);
	~ElectricAutomobile() = default;

	void charge(const unsigned);
	unsigned getPercentage() const;
private:
	unsigned batteryCapacity;
	unsigned batteryPercentage;
};

#endif // !ELECTRICAUTOMOBILE_HPP
