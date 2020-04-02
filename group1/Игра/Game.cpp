//
// Created by lyubo on 26.03.20 г..
//

#include <iostream>
#include "Game.h"


Game::Game():is_game_running(true)
{
    this->update_field();
    //this->is_game_running = true; <- това също работи
}
void Game::draw()
{
    for(int row = 0; row < FIELD_ROWS; row++)
    {
        for(int column = 0; column < FIELD_COLUMNS; column++)
        {
            std::cout << this->field[row][column];
        }
        std::cout << std::endl;
    }
}

void Game::update()
{
    char new_direction = 0;

    //TODO: Better input handling
    std::cout << "Enter where you want to go (w-up, s-down, a-left, d-right, q-exit): ";
    std::cin >> new_direction;

    while(new_direction != 'w' && new_direction != 's' && new_direction != 'a' && new_direction != 'd'
        && new_direction !='q')
    {
        std::cout << "Enter where you want to go (w-up, s-down, a-left, d-right): ";
        std::cin >> new_direction;
    }

    if(new_direction == 'q')
    {
        this->is_game_running = false;
        return;
    }
    this->snake.move(new_direction);

    if(this->has_snake_collided_with_apple())
    {
        //TODO
        this->snake.eat();
    }
    this->update_field();
    std::cout << this->snake.get_length() << std::endl;
    this->draw();
}

void Game::update_field() {
    for(int x = 0; x < FIELD_ROWS; x++)
    {
        for(int y = 0; y < FIELD_COLUMNS; y++)
        {
            this->field[x][y] = ' ';
        }
    }
    this->field[apple.get_position().get_row()][apple.get_position().get_column()] = 'A';

    unsigned snake_length = this->snake.get_length();

    Point temp = this->snake.get_positions()[0];
    this->field[temp.get_row()][temp.get_column()] = 'O';

    for(int i = 1; i < snake_length; i++)
    {
        temp = this->snake.get_positions()[i];
        std::cout << temp.get_row() << " " << temp.get_column() << std::endl;
        this->field[temp.get_row()][temp.get_column()] = '=';
    }
}

bool Game::is_game_on() const {
    return is_game_running;
}

bool Game::has_snake_collided_with_apple() const
{
    //Може и така
//    if(this->snake.get_head_position() == this->apple.get_position())
//    {
//        return true;
//    }
//    return false;

    return (this->snake.get_head_position() == this->apple.get_position());
}