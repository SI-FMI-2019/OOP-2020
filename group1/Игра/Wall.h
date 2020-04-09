//
// Created by lyubo on 9.04.20 г..
//

#ifndef CPP_GAME_WALL_H
#define CPP_GAME_WALL_H

#include "Point.h"

class Wall {
public:
    Wall() = default;
    Wall(const Point& position);

    Point get_position() const;
private:
    Point position;
};


#endif //CPP_GAME_WALL_H
