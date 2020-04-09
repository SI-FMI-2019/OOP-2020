//
// Created by lyubo on 26.03.20 г..
//

#ifndef CPP_GAME_GAME_H
#define CPP_GAME_GAME_H

#include "Snake.h"
#include "Apple.h"
#include "Wall.h"
#include "HighScoreHandler.h"

#include <iostream>
#include <cstdlib>

class Game {
public:
    static const unsigned FIELD_COLUMNS = 25;
    static const unsigned FIELD_ROWS = 10;
    static const unsigned AMOUNT_OF_WALL = (2 * (FIELD_COLUMNS + FIELD_ROWS)) - 4;

    Game();
    void draw();
    void update();
    void end();

    bool is_game_on() const;
private:
    char field[FIELD_ROWS][FIELD_COLUMNS];
    Wall walls[AMOUNT_OF_WALL];
    Snake snake;
    Apple apple;
    bool is_game_running;
    unsigned score;

    HighScoreHandler high_score;

    void update_field();
    void init_wall();
    bool has_snake_collided_with_apple() const;
    bool has_snake_collided_with_wall() const;
    bool has_snake_collided_with_itself() const;
};


#endif //CPP_GAME_GAME_H
