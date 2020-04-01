//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_SNAKE_H
#define CPP_GAME_SNAKE_H

#include <cstddef> //linux only
#include "Point.h"
class Snake {
public:
    //Big 4
    Snake();
    Snake(const Snake& from);
    Snake& operator=(const Snake& from);
    ~Snake();

    bool check_if_point_is_in_snake(const Point& to_check);
    Point get_head_position() const;
    Point* get_positions() const;
    unsigned get_length() const;
    void eat();
private:

    const int HEAD_LOCATION_INDEX = 0;
    unsigned length; //size_t = unsigned int64
    Point* snake_body;
};


#endif //CPP_GAME_SNAKE_H
