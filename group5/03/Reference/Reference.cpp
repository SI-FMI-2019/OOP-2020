#include "Reference.hpp"
#include <iostream>

Reference::Reference()
    : resource(new int)
{
    std::cout << "Reference()" << std::endl;
    *this->resource = 0;
}

// dependency
Reference::Reference(const int value)
    : resource(new int)
{
    std::cout << "Reference(const int)" << std::endl;

    *this->resource = value;
}

Reference::Reference(const Reference& other)
    : resource(new int)
{
    std::cout << "Reference(const Reference&)" << std::endl;

    *this->resource = *other.resource;
}

Reference::~Reference()
{
    std::cout << "~Reference()" << std::endl;

    delete this->resource;
}