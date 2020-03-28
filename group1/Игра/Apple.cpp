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
    std::uniform_int_distribution<> x_generator(0, Game::FIELD_WIDTH); // define the range
    std::uniform_int_distribution<> y_generator(0, Game::FIELD_HEIGHT);

    this->position = Point(x_generator(eng), y_generator(eng));
}
Point Apple::get_position() const
{
    return this->position;
}