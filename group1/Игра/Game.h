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
    static const unsigned FIELD_COLUMNS = 25;
    static const unsigned FIELD_ROWS = 10;

    Game();
    void draw();
    void update();

    bool is_game_on() const;
private:
    char field[FIELD_ROWS][FIELD_COLUMNS];
    Snake snake;
    Apple apple;
    bool is_game_running;

    void update_field();
    bool has_snake_collided_with_apple() const;
};


#endif //CPP_GAME_GAME_H
