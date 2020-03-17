#include "Complex.hpp"
#include <iostream>

Complex::Complex(const double real, const double imaginary)
    : real(real)
    , imaginary(imaginary)
{
}

// void Complex::makeComplex(const double real, const double imaginary)
// {
//     this->real = real;
//     this->imaginary = imaginary;
// }

void Complex::addComplex(const Complex& other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void Complex::productComplex(const Complex& other)
{
    const double oldReal = this->real;
    this->real = (this->real * other.real) - (this->imaginary * other.imaginary);
    this->imaginary = (oldReal * other.imaginary) + (this->imaginary * other.real);
}

void Complex::print() const
{
    std::cout << real;
    if (this->imaginary >= 0)
    {
        std::cout << " + " << this->imaginary << "i" << std::endl;
    }
    else
    {
        std::cout << " - " << -this->imaginary << "i" << std::endl;
    }
}