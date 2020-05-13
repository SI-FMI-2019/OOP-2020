#include "Rectangle.hpp"

Rectangle::Rectangle(const double width, const double heigth)
	: width(width)
	, heigth(heigth)
{
}

const double Rectangle::getArea() const
{
	return this->width * this->heigth;
}

const double Rectangle::getPerimeter() const
{
	return 2 * this->width + 2 * this->heigth;
}