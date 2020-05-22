#ifndef DATAELEMENT_HPP
#define DATAELEMENT_HPP

#include "DisplayElement.hpp"
#include <string>

class DataElement
{
public:
    virtual void registerDisplay(DisplayElement*) = 0;
    virtual void removeDisplay(const std::string&) = 0;

    virtual void setTemperature(const double&) = 0;
    virtual void setHumidity(const double&) = 0;
    virtual void setPressure(const double&) = 0;

    virtual ~DataElement() = default;
};

#endif // !DATAELEMENT_HPP