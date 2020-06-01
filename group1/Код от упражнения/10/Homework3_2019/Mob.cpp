//
// Created by lyubo on 28.05.20 г..
//

#include "Mob.h"

Mob::Mob(): Entity(), damage(0), health(0) {}
Mob::Mob(const std::string& name, const Point2D& location, const int& damage, const int& health)
    : Entity(name, location), damage(damage), health(health) {}

Mob::Mob(const std::string& name, const Point3D& location, const int& damage, const int& health)
    : Entity(name, location), damage(damage), health(health) {}

bool Mob::is_alive() const
{
    return this->health > 0;
}

int Mob::get_damage() const
{
    return this->damage;
}
int Mob::get_health() const
{
    return this->health;
}

/*void Mob::attack(Player& to_be_attacked)
{
    if(this->get_distance_to(to_be_attacked) <= 5.0)
    {
        to_be_attacked.health -= this->damage;
    }
    else
    {
        std::cout << "Distance is greater than 5!";
    }
}*/
void Mob::attack(Mob& to_be_attacked)
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

Entity::EntityType Mob::get_type() const
{
    return Entity::EntityType::MobType;
}