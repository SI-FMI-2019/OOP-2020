#include "ShapeContainer.hpp"
#include <iostream>

ShapeContainer::ShapeContainer()
	: capacity(1)
	, size(0)
	, shapes(new Shape* [1])
{
}

ShapeContainer::ShapeContainer(const unsigned cap)
	: size(0)
	, capacity(cap)
	, shapes(new Shape* [capacity])
{
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
	: size(other.size)
	, capacity(other.capacity)
	, shapes(new Shape* [capacity])
{
	for (int i = 0; i < size; i++)
	{
		this->shapes[i] = other.shapes[i];
	}
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		for (int i = 0; i < size; i++)
		{
			delete shapes[i];
		}
		delete[] shapes;

		this->size = other.size;
		this->capacity = other.capacity;
		this->shapes = new Shape* [size];
		for (int i = 0; i < size; i++)
		{
			this->shapes[i] = other.shapes[i];
		}
	}	
	return *this;
}

ShapeContainer::~ShapeContainer()
{
	for (int i = 0; i < size; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

void ShapeContainer::addShape(Shape* shape)
{
	this->shapes[this->size] = shape;
	this->size++;
}

void ShapeContainer::getAllShapesAreasAndPerimeters() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << shapes[i]->getPerimeter() << " - " << shapes[i]->getArea() << std::endl;
	}
}