#include <iostream>
#include <cstring>
#include <cmath>

#include "MyString.h"

class Beverage
{
public:
    Beverage() = default;
    Beverage(const int& code, const double& amount): beverage_code(code), amount(amount){}

    int get_code() const { return this->beverage_code; }
    double get_amount() const { return this->amount; }

    void set_code(const int& new_code)
    {
        this->beverage_code = new_code;
    }

    void set_amount(const double& new_amount)
    {
        this->amount = new_amount;
    }

    void print() const
    {
        std::cout << "Code: " << this->beverage_code << std::endl;
        std::cout << "Amount: " << this->amount << std::endl;
    }
private:
    int beverage_code;
    double amount;
};

class Coffee: virtual public Beverage{
public:
    enum CoffeeType
    {
        Arabic,
        Brazilian,
        Indian,
        Colombian
    };

    Coffee(): Beverage() { type = Arabic;}
    Coffee(const int& code, const double& amount, const CoffeeType& type): Beverage(code, amount), type(type) {}

    CoffeeType get_type() const
    {
        return this->type;
    }

    void set_type(const CoffeeType& type)
    {
        this->type = type;
    }

    void print()
    {
        Beverage::print();
        std::cout << "Coffee type: ";
        if(this->type == CoffeeType::Arabic)
        {
            std::cout << "Arabic" << std::endl;
        }
        else if(this->type == CoffeeType::Brazilian)
        {
            std::cout << "Brazilian" << std::endl;
        }
        else if(this->type == CoffeeType::Indian)
        {
            std::cout << "Indian" << std::endl;
        }
        else
        {
            std::cout << "Colombian" << std::endl;
        }
    }

private:
    CoffeeType type;
};

class Milk: virtual public Beverage
{
public:
    enum MilkType
    {
        Cow,
        Almond,
        Bull
    };

    Milk(): Beverage(){
        this->type = MilkType::Cow;
    }

    Milk(const int& code, const double& amount, const MilkType& type): Beverage(code, amount){
        this->type = type;
    }

    MilkType get_type() const
    {
        return this->type;
    }

    void set_type(const MilkType& type)
    {
        this->type = type;
    }

    void print()
    {
        Beverage::print();
        std::cout << "Milk type: ";
        if(this->type == MilkType::Cow)
        {
            std::cout << "Cow" << std::endl;
        }
        else if(this->type == MilkType::Almond)
        {
            std::cout << "Almond" << std::endl;
        }
        else
        {
            std::cout << "Bull" << std::endl;
        }
    }
private:
    MilkType type;
};

class CoffeeWithMilk: public Coffee, public Milk
{
public:
    CoffeeWithMilk(): Beverage(), Coffee(), Milk(), price(0) {}
    CoffeeWithMilk(const int& code, const double& amount, const CoffeeType& coffee_type, const MilkType milk_type, const double& price): Beverage(code, amount){
        this->Coffee::set_type(coffee_type);
        this->Milk::set_type(milk_type);
        this->price = price;
    }

    double get_price() const
    {
        return this->price;
    }

    void set_price(const double& new_price){
        this->price = new_price;
    }

    void print()
    {
        Beverage::print();

        std::cout << "Coffee type: ";
        if(this->Coffee::get_type() == CoffeeType::Arabic)
        {
            std::cout << "Arabic" << std::endl;
        }
        else if(this->Coffee::get_type() == CoffeeType::Brazilian)
        {
            std::cout << "Brazilian" << std::endl;
        }
        else if(this->Coffee::get_type() == CoffeeType::Indian)
        {
            std::cout << "Indian" << std::endl;
        }
        else
        {
            std::cout << "Colombian" << std::endl;
        }

        std::cout << "Milk type: ";
        if(this->Milk::get_type() == MilkType::Cow)
        {
            std::cout << "Cow" << std::endl;
        }
        else if(this->Milk::get_type() == MilkType::Almond)
        {
            std::cout << "Almond" << std::endl;
        }
        else
        {
            std::cout << "Bull" << std::endl;
        }
    }
private:
    double price;
};

int main()
{
    CoffeeWithMilk a(123, 0.5, Coffee::CoffeeType::Brazilian, Milk::MilkType::Cow, 1.50);
    a.print();

    return 0;
}