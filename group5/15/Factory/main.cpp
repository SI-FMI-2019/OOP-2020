#include <iostream>

class BarkingStyle
{
public:
    virtual void bark() const = 0;
};

class AgressiveBarking : public BarkingStyle
{
public:
    virtual void bark() const override
    {
        std::cout << "Arrr, I'm gonna kill you" << std::endl;
    }
};

class CalmBarking : public BarkingStyle
{
public:
    virtual void bark() const override
    {
        std::cout << "Bau, bau, feed me please" << std::endl;
    }
};

class NoBarking : public BarkingStyle
{
public:
    virtual void bark() const override
    {
        std::cout << "I'm aristocrate, I don't bark, mate" << std::endl;
    }
};

class BarkingStyleFactory
{
public:
    BarkingStyle* createBarkingStyle(const int number)
    {
        if (number == 1)
        {
            return new AgressiveBarking;
        }
        else if (number == 2)
        {
            return new CalmBarking;
        }
        else 
        {
            return new NoBarking;
        }
    }
};

class Dog
{
public:
    Dog() = default;
    void bark() const
    {
        barkingStyle->bark();
    }

    void setBarkingStyle(BarkingStyle* newBarkingStyle)
    {
        this->barkingStyle = newBarkingStyle;
    }
private:
    BarkingStyle* barkingStyle;
};

int main()
{
    Dog myDog;
    int number = 0;

    std::cin >> number;

    BarkingStyleFactory factory;
    myDog.setBarkingStyle(factory.createBarkingStyle(number));

    myDog.bark();
    return 0;
}