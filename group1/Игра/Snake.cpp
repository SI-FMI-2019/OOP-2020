//
// Created by lyubo on 26.03.20 г..
//

#include "Snake.h"

Snake::Snake() : length(2) {
    this->snake_body = new Point[this->length];

    for (int i = 0; i < this->length; i++) {
        // Point temp = Point(i+1, 1);
        // this->snake_body[i] = temp;

        this->snake_body[i] = Point(i + 1, 1); //Point(i+1, 1);
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
    Point tail = this->snake_body[this->length - 1];

//    Point parts_candidates[4];
//    parts_candidates[0] = Point(tail.get_x() + 1, tail.get_y());
//    parts_candidates[1] = Point(tail.get_x() - 1, tail.get_y());
//    parts_candidates[2] = Point(tail.get_x(), tail.get_y() + 1);
//    parts_candidates[3] = Point(tail.get_x(), tail.get_y() - 1);

    Point parts_candidates[4] = {
            Point(tail.get_x() + 1, tail.get_y()),
            Point(tail.get_x() - 1, tail.get_y()),
            Point(tail.get_x(), tail.get_y() + 1),
            Point(tail.get_x(), tail.get_y() - 1)
    };

    for (int i = 0; i < 4; i++) {
        if (!this->check_if_point_is_in_snake(parts_candidates[i])) {
            this->snake_body[this->length] = parts_candidates[i];
            i = 10; //Smarter break;
        }
    }
}

bool Snake::check_if_point_is_in_snake(const Point &to_check) {
    bool is_okay = true;
    for (int i = 0; i < this->length - 1; i++) {
        if (this->snake_body[i] == to_check) {
            is_okay = false;
            i = this->length * 10; //Умен break. Може и break, но този вариант е малко по-добър
        }
    }

    return is_okay;
}

Point* Snake::get_positions() const
{
    return this->snake_body;
}
unsigned Snake::get_length() const
{
    return this->length;
}