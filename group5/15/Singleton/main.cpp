#include <iostream>

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance()
    {
        if (instance == nullptr) 
        {
            instance = new Singleton;
        }
        return instance;
    }

    void setData(const int& newData)
    {
        data = newData;
    }

    int getData() const
    {
        return data;
    }

private:
    static Singleton* instance;
    Singleton()
        : data(10)
    {
    }
    int data;
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s = s->getInstance();
    std::cout << s->getData() << std::endl;
    s->setData(100);

    std::cout << s->getData() << std::endl;

    Singleton* second = second->getInstance();
    std::cout << second->getData() << std::endl;
    return 0;
}