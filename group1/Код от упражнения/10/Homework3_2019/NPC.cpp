//
// Created by lyubo on 28.05.20 г..
//

#include "NPC.h"

NPC::NPC(): Entity() {}
NPC::NPC(const std::string& name, const Point2D& location): Entity(name, location) {}
NPC::NPC(const std::string& name, const Point3D& location): Entity(name, location) {}

Entity::EntityType NPC::get_type() const
{
    return Entity::EntityType::NPCType;
}
bool NPC::is_alive() const
{
    return true;
}