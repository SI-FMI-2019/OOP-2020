#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:
    void makeComplex(const double, const double);
    void addComplex(const Complex&);
    void productComplex(const Complex&);
    void print() const;
private:
    double real;
    double imaginary;
};

#endif // COMPLEX_HPP