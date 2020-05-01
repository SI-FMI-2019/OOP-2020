#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
public:
	Shape() = default;

	virtual const double getArea() const 
	{
		return 0;
	}
	virtual const double getPerimeter() const 
	{
		return 0;
	}
};

#endif // !SHAPE_HPP
