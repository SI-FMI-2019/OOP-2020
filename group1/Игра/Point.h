//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_POINT_H
#define CPP_GAME_POINT_H
#include <cmath>

class Point {
public:
    Point() = default; //Създава конструктор explicitly
    Point(const unsigned& init_x, const unsigned& init_y);

    void set_x(const unsigned& new_x);
    void set_y(const unsigned& new_y);

    unsigned get_x() const;
    unsigned get_y() const;

    double get_distance_to(const Point& to);

    bool operator==(const Point& second);
private:
    unsigned x;
    unsigned y;
};


#endif //CPP_GAME_POINT_H
