#ifndef HYBRIDAUTOMOBILE_HPP
#define HYBRIDAUTOMOBILE_HPP

#include "PetrolAutomobile.hpp"
#include "ElectricAutomobile.hpp"

class HybridAutomobile : public PetrolAutomobile, public ElectricAutomobile
{
public:
	HybridAutomobile() = default;
	HybridAutomobile(const unsigned, 
					 const char*, 
					 const unsigned, 
					 const double,
					 const unsigned,
					 const double,
					 const double,
					 const unsigned,
					 const unsigned,
					 const bool);
	HybridAutomobile(const HybridAutomobile&);
	HybridAutomobile& operator=(const HybridAutomobile&);
	~HybridAutomobile() = default;

	void switchEngines();
	bool getIsEngineElectric() const;
private:
	bool isEngineElectric;
};

#endif // !HYBRIDAUTOMOBILE_HPP
