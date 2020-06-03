//
// Created by lyubo on 28.05.20 г..
//

#ifndef HOMEWORK3_2019_ENVIRONMENT_H
#define HOMEWORK3_2019_ENVIRONMENT_H

#include <vector>
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include "Point3D.h"
#include "Point2D.h"

class Environment {
public:
    static Environment* get_instance() {
        return instance;
    }

    void add(const Player& player_to_add);
    void add(const NPC& npc_to_add);
    void add(const Mob& mob_to_add);

    void generate_entities();

    void destroy_entities();

    Entity* get_closest_entity(const Player& base_point, const Entity::EntityType& type) const;
    Entity* get_entity(const int& index) const;

private:
    static Environment* instance;
    Environment();
    std::vector<Entity*> entities;
};


#endif //HOMEWORK3_2019_ENVIRONMENT_H
