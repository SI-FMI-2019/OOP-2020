//
// Created by lyubo on 30.04.20 г..
//

#include "Point3D.h"

Point3D::Point3D(const double& x, const double& y, const double& z): Point2D(x, y), z(z)
{
    this->Point2D::type = Dimension::_3D;
}

double Point3D::get_z() const
{
    return this->z;
}
double Point3D::get_distance_to(const Point2D* to) const
{
    double dist_x = this->get_x() - to->get_x();
    double dist_y = this->get_y() - to->get_y();

    double dist_z = this->z;
    if(to->get_type() == Point2D::Dimension::_3D)
    {
        dist_z -= ((Point3D*)to)->z;
    }

    return sqrt(pow(dist_x, 2) + pow(dist_y, 2) + pow(dist_z, 2));
}