#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    void setReal(double real);
    void setImaginary(double imaginary);
    double getReal() const;
    double getImaginary() const;
    ComplexNumber sum(ComplexNumber rhs) const;
    ComplexNumber multiply(ComplexNumber rhs) const;
    void print() const;
};