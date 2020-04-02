//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_POINT_H
#define CPP_GAME_POINT_H
#include <cmath>

class Point {
public:
    Point() = default; //Създава конструктор explicitly
    Point(const unsigned& initial_row, const unsigned& initial_column);

    void set_row(const unsigned& new_row);
    void set_column(const unsigned& new_column);

    unsigned get_row() const;
    unsigned get_column() const;

    double get_distance_to(const Point& to);

    bool operator==(const Point& second);
private:
    unsigned row;
    unsigned column;
};


#endif //CPP_GAME_POINT_H
