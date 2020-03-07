#include "QuadraticEquation.hpp"


void QuadraticEquation::setCoefficients(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
}

void QuadraticEquation::solve() const{
    double d = b*b - 4*a*c;
    if(d > 0) { 
        double x1 = (-b + sqrt(d))/2*a;
        double x2 = (-b - sqrt(d))/2*a;
        cout << "x1 = " << x1 << " " << "x2 = " << x2 << "\n";
    } 
    else if (d == 0) {
        double x = -b/2*a;
        cout << "x = " << x << "\n";
    } 
    else {
        double sqd = sqrt(abs(d));//squared d

        ComplexNumber x1;
        x1.setReal(-b/2*a); 
        x1.setImaginary(sqd/2*a);
        
        ComplexNumber x2;
        x2.setReal(-b/2*a); 
        x2.setImaginary(-sqd/2*a);

        x1.print();
        x2.print();
    }
}
