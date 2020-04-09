//
// Created by lyubo on 26.03.20 г..
//

#include "Apple.h"
#include "Game.h"
Apple::Apple()
{
    //TODO: Fix the bug when the Apple is inside of the snake
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> row_generator(4, Game::FIELD_ROWS - 1);
    std::uniform_int_distribution<> column_generator(2, Game::FIELD_COLUMNS - 1); // define the range

    this->position = Point(row_generator(eng), column_generator(eng));
}
Point Apple::get_position() const
{
    return this->position;
}