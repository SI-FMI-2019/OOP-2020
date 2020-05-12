#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "ShapeContainer.hpp"
#include <iostream>

int main()
{
    std::cout << sizeof(Shape) << std::endl;
    ShapeContainer shapes(10);
    Shape* circle = new Circle(3);
    shapes.addShape(circle);
    Shape* rectangle = new Rectangle(3, 4);
    shapes.addShape(rectangle);
    Shape* square = new Square(10);
    shapes.addShape(square);
    shapes.getAllShapesAreasAndPerimeters();

    // ShapeContainer cleaning up the memory instead of main
    return 0;
}