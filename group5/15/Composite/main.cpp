#include <iostream>
#include <vector>

class Component
{
public: 
    virtual void operation1() const = 0;
    virtual int getValue() const = 0;
};

class SingleComponent : public Component
{
public: 
    virtual void operation1() const override 
    {

    }
    virtual int getValue() const override 
    {
        return this->value;
    }
private:
    int value;
};

class GroupComponent : public Component
{
public:
    virtual void operation1() const override 
    {

    }
    virtual int getValue() const override 
    {
        for (auto component : components)
        {
            if (component->getValue())
            {
                return component->getValue();
            }
        }
    }

private:
    std::vector<Component*> components;
};

int main()
{
    return 0;
}