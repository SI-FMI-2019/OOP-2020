//
// Created by lyubo on 26.03.20 г..
//

#include "Point.h"

Point::Point(const unsigned& init_x, const unsigned& init_y): x(init_x), y(init_y) {}

void Point::set_x(const unsigned& new_x)
{
    this->x = new_x;
}
void Point::set_y(const unsigned& new_y)
{
    this->y = new_y;
}

unsigned Point::get_x() const
{
    return this->x;
}

unsigned Point::get_y() const
{
    return this->y;
}

double Point::get_distance_to(const Point& to)
{
    //Питагорова теорема
    //sqrt - корен-квадратен
    //pow - степен
    return sqrt(pow(to.x - this->x, 2) + pow(to.y - this->y, 2));
}

bool Point::operator==(const Point &second)
{
    return (this->x == second.x && this->y == second.y);
}
