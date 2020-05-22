#ifndef WEATERSTATION_HPP
#define WEATERSTATION_HPP

#include "DataElement.hpp"
#include <vector>

class WeaterStation : public DataElement
{
public:
	WeaterStation(const double&, const double&, const double&);
	virtual void registerDisplay(DisplayElement*) override;
    virtual void removeDisplay(const std::string&) override;

    virtual void setTemperature(const double&) override;
    virtual void setHumidity(const double&) override;
    virtual void setPressure(const double&) override;

	void notifyObserversDataChanged();

	virtual ~WeaterStation() = default;
private:
	std::vector<DisplayElement*> observers;
	double temperature;
	double humidity;
	double pressure;
};

#endif // !WEATERSTATION_HPP
