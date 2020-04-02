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
    std::uniform_int_distribution<> row_generator(3, Game::FIELD_ROWS);
    std::uniform_int_distribution<> column_generator(0, Game::FIELD_COLUMNS); // define the range

    //this->position = Point(row_generator(eng), column_generator(eng));
    this->position = Point(2, 1);
}
Point Apple::get_position() const
{
    return this->position;
}