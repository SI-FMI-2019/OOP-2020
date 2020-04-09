//
// Created by lyubo on 26.03.20 г..
//

#include <iostream>
#include "Game.h"


Game::Game() : is_game_running(true) {

    this->init_wall();
    this->update_field();
    this->score = 0;
    //this->is_game_running = true; <- това също работи
}

void Game::draw() {
    //system("cls"); //cls -> clear screen
    for (int row = 0; row < FIELD_ROWS; row++) {
        for (int column = 0; column < FIELD_COLUMNS; column++) {
            std::cout << this->field[row][column];
        }
        std::cout << std::endl;
    }
}

void Game::update() {
    char new_direction = 0;

    //TODO: Better input handling
    std::cout << "Enter where you want to go (w-up, s-down, a-left, d-right, q-exit): ";
    std::cin >> new_direction;

    while (new_direction != 'w' && new_direction != 's' && new_direction != 'a' && new_direction != 'd'
           && new_direction != 'q') {
        std::cout << "Enter where you want to go (w-up, s-down, a-left, d-right): ";
        std::cin >> new_direction;
    }

    if (new_direction == 'q') {
        this->is_game_running = false;
        return;
    }
    this->snake.move(new_direction);

    if (this->has_snake_collided_with_apple()) {
        this->score += 1;
        this->snake.eat();
        this->apple = Apple();
    }

    if(this->has_snake_collided_with_wall() || this->has_snake_collided_with_itself())
    {
        this->end();
        return;
    }
    this->update_field();
    this->draw();
}

void Game::end()
{
    this->is_game_running = false;
    std::cout << "You died ! Your high score is: " << this->score;

    std::cout << "Please enter your name: (max: 100 characters): ";
    char buffer[100];
    std::cin >> buffer;

    this->high_score.write_high_score(this->score, buffer);
}
void Game::update_field() {
    for (int x = 0; x < FIELD_ROWS; x++) {
        for (int y = 0; y < FIELD_COLUMNS; y++) {
            this->field[x][y] = ' ';
        }
    }
    this->field[apple.get_position().get_row()][apple.get_position().get_column()] = 'A';

    unsigned snake_length = this->snake.get_length();

    Point temp = this->snake.get_positions()[0];
    this->field[temp.get_row()][temp.get_column()] = 'O';

    for (int i = 1; i < snake_length; i++) {
        temp = this->snake.get_positions()[i];
        this->field[temp.get_row()][temp.get_column()] = '=';
    }

    for(int i = 0; i < AMOUNT_OF_WALL; i++)
    {
        Point current_brick = this->walls[i].get_position();
        this->field[current_brick.get_row()][current_brick.get_column()] = '*';
    }
}

bool Game::is_game_on() const {
    return is_game_running;
}

bool Game::has_snake_collided_with_apple() const {
    return (this->snake.get_head_position() == this->apple.get_position());
}

bool Game::has_snake_collided_with_wall() const {
    /*
     for(int i = 0; i < AMOUNT_OF_WALL; i++){
        if(this->snake.get_head_position() == this->walls[i].get_position())
        {
            result = true;
            break;
        }
    */
    bool result = false;
    for(Wall current_brick: this->walls)
    {
        if(this->snake.get_head_position() == current_brick.get_position())
        {
            result = true;
            break;
        }
    }
    return result;
}

bool Game::has_snake_collided_with_itself() const {
    return (this->snake.check_if_point_is_in_snake(this->snake.get_head_position(), true));
}
void Game::init_wall() {
    for (int i = 0; i < FIELD_COLUMNS; i++) {
        this->walls[i] = Wall(Point(0, i));
    }
    unsigned offset = FIELD_COLUMNS;
    for (int i = 1; i < FIELD_ROWS - 1; i++) {
        this->walls[offset] = Wall(Point(i, 0));
        offset++;
        this->walls[offset] = Wall(Point(i, FIELD_COLUMNS - 1));
        offset++;
    }
    for (int i = 0; i < FIELD_COLUMNS; i++) {
        this->walls[offset] = Wall(Point(FIELD_ROWS - 1, i));
        offset++;
    }
}