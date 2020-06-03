//
// Created by lyubo on 30.04.20 г..
//

#ifndef HOMEWORK3_2019_PLAYER_H
#define HOMEWORK3_2019_PLAYER_H

#include "Entity.h"
#include "Mob.h"
#include <iostream>
class Player: public Entity {
public:
    Player();
    Player(const std::string& name, const Point2D& location, const int& damage, const int& health);
    Player(const std::string& name, const Point3D& location, const int& damage, const int& health);

    bool is_alive() const override;

    int get_damage() const;
    int get_health() const;

    void attack(Player& to_be_attacked);
    //void attack(Mob& to_be_attacked);

    EntityType get_type() const override;

    friend class Mob;
private:
    int damage;
    int health;
};


#endif //HOMEWORK3_2019_PLAYER_H
