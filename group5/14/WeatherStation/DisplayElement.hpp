#ifndef DISPLAYELEMENT_HPP
#define DISPLAYELEMENT_HPP

#include <string>

class DisplayElement
{
public:
    virtual void update(const double&, const double&, const double&) = 0;
    virtual void display() const = 0;
    virtual std::string getId() const = 0;

    virtual ~DisplayElement() = default;
};

#endif // !DISPLAYELEMENT_HPP