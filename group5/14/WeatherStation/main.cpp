#include "DataElement.hpp"
#include "DisplayElement.hpp"
#include "WeaterStation.hpp"
#include "WeatherDisplay.hpp"

#include <chrono>
#include <thread>

int main()
{
    DataElement* weatherStation = new WeaterStation(23.5, 90, 1000);
    DisplayElement* weatherDisplay = new WeatherDisplay("1234", 23.5, 90, 1000);
    DisplayElement* secondWeatherDisplay = new WeatherDisplay("12345", 23.5, 90, 1000);

    weatherStation->registerDisplay(weatherDisplay);
    weatherStation->registerDisplay(secondWeatherDisplay);
    weatherStation->removeDisplay("1234");

    weatherStation->setTemperature(18);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    weatherStation->setHumidity(52);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    weatherStation->setPressure(1021);

    delete weatherStation;
    delete weatherDisplay;
    return 0;
}