//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_GAME_H
#define CPP_GAME_GAME_H
#include "Snake.h"
#include "Apple.h"
#include <iostream>

class Game {
public:
    static const unsigned FIELD_WIDTH = 80;
    static const unsigned FIELD_HEIGHT = 25;

    Game();
    void draw();
private:
    char field[FIELD_WIDTH][FIELD_HEIGHT];
    Snake snake;
    Apple apple;
};


#endif //CPP_GAME_GAME_H
