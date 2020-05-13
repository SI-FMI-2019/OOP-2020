#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(const double, const double);

	virtual const double getArea() const override;
	virtual const double getPerimeter() const override;

	virtual ~Rectangle()
	{
		std::cout << "~Rectangle()" << std::endl;
	}
private:
	double width;
	double heigth;
};

#endif // !RECTANGLE_HPP
