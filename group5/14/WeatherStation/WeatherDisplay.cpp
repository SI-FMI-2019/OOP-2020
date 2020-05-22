#include "WeatherDisplay.hpp"

#include <iostream>

WeatherDisplay::WeatherDisplay(const std::string& id,
	const double& temperature,
	const double& humidity,
	const double& pressure)
	: id(id)
	, temperature(temperature)
	, humidity(humidity)
	, pressure(pressure)
{
}

void WeatherDisplay::update(const double& temperature, 
	const double& humidity, 
	const double& pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	this->display();
}

void WeatherDisplay::display() const
{
	std::cout << "Current conditions: " << std::endl;
	std::cout << "Temperature: " << this->temperature << " ˚C" << std::endl;
	std::cout << "Humidity: " << this->humidity << " %" << std::endl;
	std::cout << "Pressure: " << this->pressure << " hPa" << std::endl;
	std::cout << "==============================" << std::endl;
}

std::string WeatherDisplay::getId() const
{
	return this->id;
}