#include "Vehicle.hpp"
#include "Car.hpp"

class Shape
{
private:
    double width;
}

class Rectangle : public Shape
{
public:
    void setWidth(double);
    void setHeight(double);
private:
    double width;
    double height;
}

class Square : public Shape
{
// public:
//     void setWidth(double);  
}

int main()
{
    // Vehicle v("Ford Focus", "CA1234AS", 23.6);
    // v.print();

    Car c("Ford Focus", "CA1234AS", 23.6, 5);
    Car z;

    z = c;
    z.print();

    return 0;
}