//
// Created by lyubo on 30.04.20 г..
//

#include "Point2D.h"

Point2D::Point2D(const double& x, const double& y): x(x), y(y), type(Dimension::_2D) {}

double Point2D::get_x() const
{
    return this->x;
}
double Point2D::get_y() const
{
    return this->y;
}
double Point2D::get_distance_to(const Point2D* to) const
{
    double dist_x = this->x - to->x;
    double dist_y = this->y - to->y;

    return sqrt(pow(dist_x, 2) + pow(dist_y, 2));
}

Point2D::Dimension Point2D::get_type() const {
    return this->type;
}
