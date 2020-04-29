#include <iostream>
#include <time.h>

class Shape
{
public:
    virtual void draw()
    {
        std::cout << "I am a Shape" << std::endl; 
    }
};

class Circle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "I am a Circle" << std::endl; 
    }
};

class Rectangle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "I'm a Rectangle" << std::endl;
    }
};

class Square : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "I'm a Square" << std::endl;
    }
};

int main()
{
    const int LENGTH = 5;

    std::cout << sizeof(Shape) << std::endl;

    Shape** shapes = new Shape* [LENGTH]; 

    // shapes[0] = new Circle;
    // shapes[1] = new Rectangle;
    // shapes[2] = new Square;
    // shapes[3] = new Shape;
    // shapes[4] = new Rectangle;

    srand(time(nullptr));

    for (int i = 0; i < LENGTH; i++)
    {
        int random = rand() % 3;
        switch (random)
        {
            case 0:
                shapes[i] = new Circle;
                break;
            case 1:
                shapes[i] = new Rectangle;
                break;
            case 2:
                shapes[i] = new Square;
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < LENGTH; i++)
    {
        shapes[i]->draw();
    }
    
    for (int i = 0; i < LENGTH; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}