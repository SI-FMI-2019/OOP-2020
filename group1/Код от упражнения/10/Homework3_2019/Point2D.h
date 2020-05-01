//
// Created by lyubo on 30.04.20 г..
//

#ifndef HOMEWORK3_2019_POINT2D_H
#define HOMEWORK3_2019_POINT2D_H

#include <math.h>
class Point2D {

public:
    enum Dimension{
        _2D,
        _3D
    };

    Point2D(const double& x = 0, const double& y = 0);

    double get_x() const;
    double get_y() const;
    virtual double get_distance_to(const Point2D* to) const;

    Dimension get_type() const;

protected:
    Dimension type;

private:
    double x;
    double y;
};



#endif //HOMEWORK3_2019_POINT2D_H
