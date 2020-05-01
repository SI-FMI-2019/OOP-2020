//
// Created by lyubo on 30.04.20 г..
//

#include "Player.h"

Player::Player(): Entity(), damage(0), health(0){}
Player::Player(const int& damage, const int& health):damage(damage), health(health){}

Player::Player(const std::string& name, const Point2D& location, const int& damage, const int& health): Player(damage, health)
{
    Player::Entity(name, location);
}
Player(const std::string& name, const Point3D& location, const int& damage, const int& health);

bool is_alive() const override;

int get_damage() const;
int get_health() const;