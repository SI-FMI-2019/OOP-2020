#include "QuadraticEquation.hpp"

int main(){
    QuadraticEquation first;
    first.setCoefficients(1,4,5);
    first.solve();
    return 0;
}