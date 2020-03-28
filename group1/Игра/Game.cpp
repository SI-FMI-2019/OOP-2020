//
// Created by lyubo on 26.03.20 г..
//

#include <iostream>
#include "Game.h"


Game::Game()
{
    //X = 0; Y = 0 е в горния-ляв ъгъл
    this->snake = Snake(); //Това не е нужно
    this->apple = Apple(); //Това не е нужно

    for(int x = 0; x < FIELD_WIDTH; x++)
    {
        for(int y = 0; y < FIELD_HEIGHT; y++)
        {
            this->field[x][y] = ' ';
        }
    }

    this->field[apple.get_position().get_x()][apple.get_position().get_y()] = 'A';

    unsigned snake_length = this->snake.get_length();

    for(int i = 0; i < snake_length; i++)
    {
        Point temp = this->snake.get_positions()[i];
        this->field[temp.get_x()][temp.get_y()] = '=';
    }

}
void Game::draw()
{
    for(int x = 0; x < FIELD_WIDTH; x++)
    {
        for(int y = 0; y < FIELD_HEIGHT; y++)
        {
            std::cout << this->field[y][x];
        }
        std::cout << std::endl;
    }
}