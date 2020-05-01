#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape.hpp"

class Square : public Shape
{
public:
	Square(const double);

	virtual const double getArea() const override;
	virtual const double getPerimeter() const override;
private:
	double side;
};

#endif // !SQUARE_HPP
