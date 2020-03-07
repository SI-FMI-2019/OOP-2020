#include <iostream>
#include <cmath>
#include "ComplexNumber.hpp"
using namespace std;


class QuadraticEquation{
private:
    double a;
    double b;
    double c;
public:
    void setCoefficients(double a, double b, double c);
    void solve() const;
};
