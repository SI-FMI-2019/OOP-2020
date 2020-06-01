//
// Created by lyubo on 28.05.20 г..
//

#ifndef HOMEWORK3_2019_MOB_H
#define HOMEWORK3_2019_MOB_H

#include "Entity.h"
#include "Player.h"
#include <iostream>

class Mob:public Entity {
public:
    Mob();
    Mob(const std::string& name, const Point2D& location, const int& damage, const int& health);
    Mob(const std::string& name, const Point3D& location, const int& damage, const int& health);

    bool is_alive() const override;

    int get_damage() const;
    int get_health() const;

    //void attack(Player& to_be_attacked);
    void attack(Mob& to_be_attacked);

    Entity::EntityType get_type() const override;

    friend class Player;
private:
    int damage;
    int health;
};


#endif //HOMEWORK3_2019_MOB_H
