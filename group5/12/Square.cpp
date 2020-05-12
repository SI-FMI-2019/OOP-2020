#include "Square.hpp"

Square::Square(const double side)
	: side(side)
{
}

const double Square::getArea() const
{
	return this->side * this->side;
}

const double Square::getPerimeter() const
{
	return 4 * this->side;
}