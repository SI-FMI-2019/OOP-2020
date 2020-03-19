#include "Vector.hpp"

#include <iostream>

Vector::Vector()
    : values(nullptr)
    , size(0)
    , capacity(0)
{
}

Vector::Vector(const size_t capacity)
    : values(new int [capacity])
    , size(0)
    , capacity(capacity)
{
}

Vector::Vector(const Vector& other)
{
    copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        deallocateValues();
        copyFrom(other);
    }
    return *this;
}

Vector::~Vector()
{
    deallocateValues();
}

void Vector::pushBack(const int value)
{
    if (this->values == nullptr)
    {
        this->capacity = 1;
        this->values = new int [this->capacity];
    }
    else
    {
        resize();
    }

    this->values[this->size] = value;
    this->size++;
}

void Vector::printVector() const
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::copyFrom(const Vector& other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->values = new int [other.capacity];
    for (size_t i = 0; i < other.size; i++)
    {
        this->values[i] = other.values[i];
    }
}

void Vector::deallocateValues()
{
    if (this->values != nullptr)
    {
        delete[] this->values;
    }
}

void Vector::resize()
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        int* placeholder = new int [this->capacity];
        for (size_t i = 0; i < this->size; i++)
        {
            placeholder[i] = this->values[i];
        }
        deallocateValues();
        this->values = placeholder;

        std::cout << "resized" << std::endl;
    }
}