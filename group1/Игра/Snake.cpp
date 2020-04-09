//
// Created by lyubo on 26.03.20 г..
//

#include "Snake.h"
#include "Game.h"

Snake::Snake() : length(3) {
    this->snake_body = new Point[this->length];

    for (int i = 0; i < this->length; i++) {
        this->snake_body[i] = Point(1, i + 2); //Point(i, i+1)
    }
}

Snake::Snake(const Snake &from) : length(from.length) {
    this->snake_body = new Point[from.length];

    for (int i = 0; i < this->length; i++) {
        this->snake_body[i] = from.snake_body[i];
    }
}

Snake &Snake::operator=(const Snake &from) {
    if (this != &from) {
        delete[] this->snake_body;

        this->length = from.length;
        this->snake_body = new Point[from.length];

        for (int i = 0; i < this->length; i++) {
            this->snake_body[i] = from.snake_body[i];
        }
    }
    return *this;
}

Snake::~Snake() {
    delete[] this->snake_body;
}

Point Snake::get_head_position() const {
    return this->snake_body[HEAD_LOCATION_INDEX];
}

void Snake::eat() {
    this->length++;

    Point *new_snake_body = new Point[this->length];

    for (int i = 0; i < this->length - 1; i++) {
        new_snake_body[i] = this->snake_body[i];
    }

    delete[] this->snake_body;
    this->snake_body = new_snake_body;

    //Ще проверим, в околност на последната част от змията, дали има място
    Point tail = this->snake_body[this->length - 2];

    Point parts_candidates[4] = {
            Point(tail.get_row() + 1, tail.get_column()),
            Point(tail.get_row() - 1, tail.get_column()),
            Point(tail.get_row(), tail.get_column() + 1),
            Point(tail.get_row(), tail.get_column() - 1)
    };

    for (int i = 0; i < 4; i++) {
        if (!this->check_if_point_is_in_snake(parts_candidates[i])) {
            this->snake_body[this->length - 1] = parts_candidates[i];
            //i = 10; //Smarter break;
        }
    }
}

bool Snake::check_if_point_is_in_snake(const Point &to_check, const bool& ignore_head) const {
    bool is_okay = false;
    //for (int i = ignore_head; i < this->length - 1; i++) { <- кратко, но нечетимо

    int i = 0;

    if(ignore_head)
    {
        i = 1;
    }
    for (; i < this->length - 1; i++) {
        if (this->snake_body[i] == to_check) {
            is_okay = true;
            break;
        }
    }
    return is_okay;
}

Point *Snake::get_positions() const {
    return this->snake_body;
}

unsigned Snake::get_length() const {
    return this->length;
}

void Snake::move(const char &direction) {
    auto snake_position = this->snake_body[HEAD_LOCATION_INDEX]; //auto -> Point

    if (Snake::check_if_move_is_inside(snake_position, direction)) {
        //CHANGED HERE
        for (int i = this->length - 1; i > 0; i--) {
            this->snake_body[i] = this->snake_body[i - 1];
        }
        if (direction == 'w') {
            if (snake_position.get_row() - 1 >= 0) {
                this->snake_body[HEAD_LOCATION_INDEX].set_row(snake_position.get_row() - 1);
            }
        } else if (direction == 's') {
            if (snake_position.get_row() + 1 < Game::FIELD_ROWS) {
                this->snake_body[HEAD_LOCATION_INDEX].set_row(snake_position.get_row() + 1);
            }
        } else if (direction == 'a') {
            if (snake_position.get_column() - 1 >= 0) {
                this->snake_body[HEAD_LOCATION_INDEX].set_column(snake_position.get_column() - 1);
            }
        } else if (direction == 'd') {
            if (snake_position.get_column() + 1 < Game::FIELD_COLUMNS) {
                this->snake_body[HEAD_LOCATION_INDEX].set_column(snake_position.get_column() + 1);
            }
        }
    }
}

bool Snake::check_if_move_is_inside(const Point &location, const char &direction) {
    if (direction == 'w') {
        return (location.get_row() - 1 >= 0);
    } else if (direction == 's') {
        return (location.get_row() + 1 < Game::FIELD_ROWS);
    } else if (direction == 'a') {
        return (location.get_column() - 1 >= 0);
    } else if (direction == 'd') {
        return (location.get_column() + 1 < Game::FIELD_COLUMNS);
    }
    return false;
}