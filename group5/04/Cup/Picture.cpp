#include "Picture.hpp"

#include <iostream>
#include <cstring>

Picture::Picture()
    : name(nullptr)
    , heigth(0)
    , width(0)
{
    std::cout << "Picture()" << std::endl;
}

Picture::Picture(const char* name, const unsigned heigth, const unsigned width)
    : name(new char [strlen(name) + 1])
    , heigth(heigth)
    , width(width)
{
    std::cout << "Picture(const char*, const unsigned, const unsigned)" << std::endl;
    strncpy(this->name, name, strlen(name));
    this->name[strlen(this->name)] = '\0';
}

Picture::Picture(const Picture& other)
    : name(new char [strlen(other.name) + 1])
    , heigth(other.heigth)
    , width(other.width)
{
    std::cout << "Picture(const Picture&)" << std::endl;
    strncpy(this->name, other.name, strlen(other.name));
    this->name[strlen(this->name)] = '\0';
}

Picture& Picture::operator=(const Picture& other)
{
    std::cout << "Picture operator=" << std::endl;
    if (this != &other)
    {
        if (this->name != nullptr)
        {
            delete[] this->name;
        }
        this->name = new char [strlen(other.name) + 1];
        strncpy(this->name, other.name, strlen(other.name));
        this->name[strlen(this->name)] = '\0';
        this->heigth = other.heigth;
        this->width = other.width;
    }
    return *this;
}

Picture::~Picture()
{
    std::cout << "~Picture()" << std::endl;
    
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
}

void Picture::printInfo() const
{
    std::cout << this->name << std::endl;
    std::cout << this->heigth << std::endl;
    std::cout << this->width << std::endl;
}