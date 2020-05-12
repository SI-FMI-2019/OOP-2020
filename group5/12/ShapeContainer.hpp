#ifndef SHAPECONTAINER_HPP
#define SHAPECONTAINER_HPP

#include "Shape.hpp"

class ShapeContainer
{
public:
	ShapeContainer();
	ShapeContainer(const unsigned);
	ShapeContainer(const ShapeContainer&);
	ShapeContainer& operator=(const ShapeContainer&);
	~ShapeContainer();

	void addShape(Shape*);
	void getAllShapesAreasAndPerimeters() const;
private:
	Shape** shapes;
	unsigned size;
	unsigned capacity;
};

#endif // !SHAPECONTAINER_HPP
