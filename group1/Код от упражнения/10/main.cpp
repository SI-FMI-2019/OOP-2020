#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Vehicle.h"

class Foo{
private:
    int* data;
public:
    Foo(): data(new int(5))
    {
        std::cout << "Foo() called" << std::endl;
    }
    Foo(const Foo& from)
    {
        this->data = new int(*from.data);
    }

    Foo& operator=(const Foo& from)
    {
        if(this != &from)
        {
            delete this->data;

            this->data = new int;
            *this->data = *from.data;
        }
        return *this;
    }

     virtual ~Foo()
     {
         std::cout << "~Foo() called" << std::endl;
        delete this->data;
     }
};

class Bar: public Foo{
private:
    int* more_data;
public:
    Bar(): more_data(new int(6)), Foo()
    {
        std::cout << "Bar() called" << std::endl;
    }
    Bar(const Bar& from): Foo(from){
        this->more_data = new int(*from.more_data);
    }
    Bar& operator= (const Bar& from)
    {
        if(this != &from)
        {
            this->Foo::operator=(from);
            delete this->more_data;

            this->more_data = new int;
            *this->more_data = *from.more_data;
        }
        return *this;
    }

    ~Bar()
    {
        std::cout << "~Bar() called" <<  std::endl;
        delete this->more_data;
    }
};
int main()
{
    Foo* b = new Bar();
    delete b;
    return 0;
}