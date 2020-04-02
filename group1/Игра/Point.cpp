//
// Created by lyubo on 26.03.20 г..
//

#include "Point.h"

Point::Point(const unsigned& initial_row, const unsigned& initial_column): row(initial_row), column(initial_column) {}

void Point::set_row(const unsigned& new_row)
{
    this->row = new_row;
}
void Point::set_column(const unsigned& new_column)
{
    this->column = new_column;
}

unsigned Point::get_row() const
{
    return this->row;
}

unsigned Point::get_column() const
{
    return this->column;
}

double Point::get_distance_to(const Point& to)
{
    //Питагорова теорема
    //sqrt - корен-квадратен
    //pow - степен
    return sqrt(pow(to.row - this->row, 2) + pow(to.column - this->column, 2));
}

bool Point::operator==(const Point &second)
{
    return (this->row == second.row && this->column == second.column);
}
