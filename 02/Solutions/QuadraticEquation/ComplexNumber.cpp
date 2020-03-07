#include "ComplexNumber.hpp"

void ComplexNumber::setReal(double real){
    this->real = real;
}
void ComplexNumber::setImaginary(double imaginary){
    this->imaginary = imaginary;
}
double ComplexNumber::getReal() const{
    return real;
}
double ComplexNumber::getImaginary() const{
    return imaginary;
}


ComplexNumber ComplexNumber::sum(ComplexNumber rhs) const{
    ComplexNumber result;
    result.setReal(this->getReal() + rhs.getReal());
    result.setImaginary(this->getImaginary() + rhs.getImaginary());
    return result;
}

ComplexNumber ComplexNumber::multiply(ComplexNumber rhs) const{
    ComplexNumber result;
    result.setReal(this->getReal()*rhs.getReal() - this->getImaginary()*rhs.getImaginary());
    result.setImaginary(this->getReal()*rhs.getImaginary() + this->getImaginary()*rhs.getReal());
    return result;
}

void ComplexNumber::print() const{
    if(imaginary >= 0){
        cout << real << "+" << imaginary << "i" << "\n";    
    }
    else{
        cout << real << imaginary << "i" << "\n";
    }
}