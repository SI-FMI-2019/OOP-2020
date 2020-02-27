#include <iostream>

struct Snake
{
    double x;
    double y;
};

void setX(Snake& snake, double newX)
{
    snake.x = newX;
}

void setY(Snake& snake, double newY)
{
    snake.y = newY;
}

double getX(const Snake& snake)
{
    return snake.x;
}

double getY(const Snake& snake)
{
    return snake.y;
}

int main()
{
    Snake snake;
    setX(snake, 10);
    // std::cout << snake.x << std::endl;

    setY(snake, 12);
    // std::cout << snake.y << std::endl;

    std::cout << getX(snake) << std::endl;

    std::cout << getY(snake) << std::endl;

    return 0;
}