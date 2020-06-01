//
// Created by lyubo on 30.04.20 г..
//
#include "Player.h"

Player::Player(): Entity(), damage(0), health(0){}

Player::Player(const std::string& name, const Point2D& location, const int& damage, const int& health)
    : Entity(name, location),damage(damage), health(health) {}
Player::Player(const std::string& name, const Point3D& location, const int& damage, const int& health)
    : Entity(name, location),damage(damage), health(health) {}

bool Player::is_alive() const
{
    return this->health > 0;
}

int Player::get_damage() const
{
    return this->damage;
}
int Player::get_health() const
{
    return this->health;
}


void Player::attack(Player &to_be_attacked)
{
    if(this->get_distance_to(to_be_attacked) <= 5.0)
    {
        to_be_attacked.health -= this->damage;
    }
    else
    {
        std::cout << "Distance is greater than 5!";
    }
}

/*void Player::attack(Mob &to_be_attacked) {
    if(this->get_distance_to(to_be_attacked) <= 5.0)
    {
        to_be_attacked.health -= this->damage;
    }
    else
    {
        std::cout << "Distance is greater than 5!";
    }
}*/


Entity::EntityType Player::get_type() const
{
    return Entity::EntityType::PlayerType;
}