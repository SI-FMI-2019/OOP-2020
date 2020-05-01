//
// Created by lyubo on 30.04.20 г..
//

#ifndef HOMEWORK3_2019_PLAYER_H
#define HOMEWORK3_2019_PLAYER_H

#include "Entity.h"
class Player: public Entity {
public:
    Player();
    Player(const std::string& name, const Point2D& location, const int& damage, const int& health);
    Player(const std::string& name, const Point3D& location, const int& damage, const int& health);

    bool is_alive() const override;

    int get_damage() const;
    int get_health() const;


private:
    Player(const int& damage, const int& health);
    int damage;
    int health;
};


#endif //HOMEWORK3_2019_PLAYER_H
