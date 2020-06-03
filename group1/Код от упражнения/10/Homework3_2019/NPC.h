//
// Created by lyubo on 28.05.20 г..
//

#ifndef HOMEWORK3_2019_NPC_H
#define HOMEWORK3_2019_NPC_H

#include "Entity.h"

class NPC: public Entity {
public:
    NPC();
    NPC(const std::string& name, const Point2D& location);
    NPC(const std::string& name, const Point3D& location);
    Entity::EntityType get_type() const override;
    bool is_alive() const override ;
};


#endif //HOMEWORK3_2019_NPC_H
