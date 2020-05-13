#include "Circle.hpp"
#include <cmath>

Circle::Circle(const double radius)
	: radius(radius)
{
}

const double Circle::getArea() const
{
	return this->radius * this->radius * M_PI;
}

const double Circle::getPerimeter() const
{
	return 2 * this->radius * M_PI;
}