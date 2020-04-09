//
// Created by lyubo on 9.04.20 г..
//

#include "Wall.h"

Wall::Wall(const Point &position) {
    this->position = position;
}

Point Wall::get_position() const {
    return this->position;
}