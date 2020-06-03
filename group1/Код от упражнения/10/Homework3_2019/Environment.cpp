//
// Created by lyubo on 28.05.20 г..
//

#include "Environment.h"

Environment* Environment::instance = new Environment();

Environment::Environment() = default;

void Environment::add(const Player& player_to_add)
{
    this->entities.push_back(new Player(player_to_add));
}
void Environment::add(const NPC& npc_to_add)
{
    this->entities.push_back(new NPC(npc_to_add));
}
void Environment::add(const Mob& mob_to_add)
{
    this->entities.push_back(new Mob(mob_to_add));
}

void Environment::generate_entities()
{
    for(int i = 1; i < 5; i++)
    {
        this->add(Player("Lyubo " + std::to_string(i), Point3D(i, i + 3), i * 2, i * 10));
        this->add(Mob("Mob Rules " + std::to_string(i), Point3D(i + 2, i + 3), i, i));
        this->add(NPC("Shop keeper " + std::to_string(i), Point3D(i, i + 3)));
    }
}

void Environment::destroy_entities()
{
    for(Entity* entity: this->entities)
    {
        delete entity;
    }
}

Entity* Environment::get_closest_entity(const Player& base_point, const Entity::EntityType& type) const
{
    double min_distance = 0;
    Entity* result;
    for(Entity* entity: this->entities)
    {
        if(entity->get_distance_to(base_point) < min_distance && entity->get_type() == type)
        {
            result = entity;
            min_distance = entity->get_distance_to(base_point);
        }
    }
    return result;
}

Entity* Environment::get_entity(const int& index) const
{
    return this->entities[index];
}