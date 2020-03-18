#include "Complex.hpp"
#include <iostream>

Complex::Complex(const double real, const double imaginary)
    : real(real)
    , imaginary(imaginary)
{
}

Complex Complex::operator+(const Complex& other)
{
    Complex result(this->real + other.real, this->imaginary + other.imaginary);
    return result;
}

Complex Complex::operator*(const Complex& other)
{
    const double oldReal = this->real;
    Complex result((this->real * other.real) - (this->imaginary * other.imaginary),
                    (oldReal * other.imaginary) + (this->imaginary * other.real));

    return result;
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