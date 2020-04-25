#include <iostream>
#include <cstring>

class SmartDevice
{
public:
    SmartDevice():CPU_speed(1.0), RAM(4), HDD_space(64) {}
    SmartDevice(const double& CPU, const int& RAM, const int& HDD): CPU_speed(CPU), RAM(RAM), HDD_space(HDD){}

    double get_CPU_speed() const
    {
        return this->CPU_speed;
    }

    int get_RAM() const
    {
        return this->RAM;
    }

    int get_HDD() const
    {
        return this->HDD_space;
    }

protected:
    double CPU_speed;
    int RAM;
    int HDD_space;
};

class Smartphone: virtual public SmartDevice
{
public:
    Smartphone(): SmartDevice(), sim_type(3){}
    Smartphone(const int& sim): sim_type(sim), SmartDevice(){}
    Smartphone(const double& CPU, const int& RAM, const int& HDD, const int& sim): SmartDevice(CPU, RAM, HDD), sim_type(sim){}

    int get_sim_type() const
    {
        return this->sim_type;
    }

    void print() const
    {
        std::cout << this->SmartDevice::CPU_speed << " " << this->SmartDevice::HDD_space << " " << this->SmartDevice::RAM << this->sim_type;
    }
protected:
    int sim_type; //2 (EDGE), 3G, 4G, 5G
};

class Tablet: virtual public SmartDevice
{
public:
    Tablet(): SmartDevice(), has_stylus(false) {}
    Tablet(const bool& stylus): has_stylus(stylus), SmartDevice() {}
    Tablet(const double& CPU, const int& RAM, const int& HDD, const bool& stylus): SmartDevice(CPU, RAM, HDD), has_stylus(stylus) {}

    bool get_stylus() const
    {
        return this->has_stylus;
    }

    void print() const
    {
        std::cout << this->SmartDevice::CPU_speed << " " << this->SmartDevice::HDD_space << " " << this->SmartDevice::RAM << this->has_stylus;
    }

protected:
    bool has_stylus;
};

class Phablet: public Smartphone, public Tablet
{
public:
    Phablet(): SmartDevice(), Smartphone(), Tablet() {}
    Phablet(const double& CPU, const int& RAM, const int& HDD, const int& sim, const bool& stylus): SmartDevice(CPU, RAM, HDD), Smartphone(sim_type), Tablet(stylus)
    {}

    void print() const
    {
        std::cout << this->SmartDevice::CPU_speed << this->SmartDevice::HDD_space << " " << this->SmartDevice::RAM << this->Smartphone::sim_type
                  << this->Tablet::has_stylus << std::endl;
    }
private:

};
