//
// Created by lyubo on 30.04.20 г..
//

#ifndef HOMEWORK3_2019_POINT3D_H
#define HOMEWORK3_2019_POINT3D_H
#include "Point2D.h"

class Point3D: public Point2D {
public:
    Point3D(const double& x = 0, const double& y = 0, const double& z = 0);

    double get_z() const;
    double get_distance_to(const Point2D* to) const override;
private:
    double z;
};


#endif //HOMEWORK3_2019_POINT3D_H
