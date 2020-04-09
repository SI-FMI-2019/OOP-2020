#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle 
{
public:
    Vehicle();
    Vehicle(const char*, const char*, const double&);    
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
    ~Vehicle();

    void print() const;
    void fuel(const double&);
private:
    char* model;
    char* registrationPlate;
    double fuelLiters;
    
    void copyFrom(const Vehicle& other);
};

#endif // VEHICLE_HPP