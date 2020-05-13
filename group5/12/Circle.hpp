#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
public:
	Circle(const double);

	virtual const double getArea() const override;
	virtual const double getPerimeter() const override;

	virtual ~Circle()
	{
		std::cout << "~Circle()" << std::endl;
	}
private:
	double radius;
};

#endif // !CIRCLE_HPP
