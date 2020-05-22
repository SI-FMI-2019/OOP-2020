#ifndef WEATHERDISPLAY_HPP
#define WEATHERDISPLAY_HPP

#include "DisplayElement.hpp"

class WeatherDisplay : public DisplayElement
{
public:
	WeatherDisplay() = default;
	WeatherDisplay(const std::string&, const double&, const double&, const double&);
	virtual void update(const double&, const double&, const double&) override;
    virtual void display() const override;
	virtual std::string getId() const override;

	virtual ~WeatherDisplay() = default;
private:
	std::string id;
	double temperature;
	double humidity;
	double pressure;
};

#endif // !WEATHERDISPLAY_HPP
