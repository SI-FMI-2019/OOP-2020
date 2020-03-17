#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:
    Complex(const Complex&) = default;
    Complex(const double real = 0, const double imaginary = 0);
    // void makeComplex(const double, const double);
    void addComplex(const Complex&);
    void productComplex(const Complex&);
    void print() const;
    ~Complex() = default;
private:
    double real;
    double imaginary;
};

#endif // COMPLEX_HPP

