#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class Shape
{
public:
	Shape() = default;

	virtual const double getArea() const = 0; // pure virtual method

	virtual const double getPerimeter() const = 0; // pure virtual method

	virtual ~Shape()
	{
		std::cout << "~Shape()" << std::endl;
	}
};

#endif // !SHAPE_HPP