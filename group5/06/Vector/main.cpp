#include "Vector.hpp"
#include "Complex.hpp"

int main()
{
    Vector<int> v;
    v.pushBack(4);
    v.pushBack(12);
    v.pushBack(8);
    v.pushBack(0);
    v.pushBack(90);

    Vector<char> v1;
    v1.pushBack('3');
    v1.pushBack('d');
    v1.pushBack('a');
    v1.printVector();

    Complex z1(2, 9);
    Complex z2(4, 8);
    Vector<Complex> vComplex;
    vComplex.pushBack(z1);
    vComplex.pushBack(z2);

    Complex z3;
    z3 = vComplex.popBack();
    z3.print();

    return 0;
}