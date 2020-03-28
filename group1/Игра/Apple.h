//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_APPLE_H
#define CPP_GAME_APPLE_H
#include "Point.h"
#include <random>

class Apple {
public:
    Apple();
    Point get_position() const;
private:
    Point position;
};


#endif //CPP_GAME_APPLE_H
