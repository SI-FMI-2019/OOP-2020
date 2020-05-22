#include "WeaterStation.hpp"

WeaterStation::WeaterStation(const double& temperature,
	const double& humidity,
	const double& pressure)
	: temperature(temperature)
	, humidity(humidity)
	, pressure(pressure)
{
}

void WeaterStation::registerDisplay(DisplayElement* display)
{
	observers.push_back(display);
}

void WeaterStation::removeDisplay(const std::string& id)
{
	for (auto i = observers.begin(); i != observers.end(); i++)
	{
		if ((*i)->getId() == id)
		{
			observers.erase(i);
			i--;
		}	
	}
}

void WeaterStation::setTemperature(const double& newTemp)
{
	this->temperature = newTemp;
	notifyObserversDataChanged();
}

void WeaterStation::setHumidity(const double& newHumidity)
{
	this->humidity = newHumidity;
	notifyObserversDataChanged();
}

void WeaterStation::setPressure(const double& newPressure)
{
	this->pressure = newPressure;
	notifyObserversDataChanged();
}

void WeaterStation::notifyObserversDataChanged()
{
	for (auto observer : observers)
	{
		observer->update(temperature, humidity, pressure);
	}
}