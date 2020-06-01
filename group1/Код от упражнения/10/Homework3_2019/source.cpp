//
// Created by lyubo on 28.05.20 г..
//

#include <iostream>
#include <vector>

class Foo
{
public:
    Foo()
    {
        std::cout << "Foo()" << std::endl;
        this->value = new int(5);
    }
    virtual ~Foo()
    {
        std::cout << "~Foo()" << std::endl;
        delete this->value;
    }
    int* value;
};

class Bar: public Foo
{
public:
    int* another_value;
    Bar(): Foo()
    {
        std::cout << "Bar()" << std::endl;
        this->another_value = new int(10);
    }

    ~Bar()
    {
        std::cout << "~Bar()" << std::endl;
        delete this->another_value;
    }
};

int main()
{
    std::vector<Foo*> temp;
    temp.push_back(new Bar());

    for(Foo* item: temp)
    {
        delete item;
    }
}
