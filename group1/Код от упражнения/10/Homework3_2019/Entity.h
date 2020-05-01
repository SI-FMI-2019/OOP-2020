//
// Created by lyubo on 30.04.20 г..
//

#ifndef HOMEWORK3_2019_ENTITY_H
#define HOMEWORK3_2019_ENTITY_H

#include <string>
#include "Point2D.h"
#include "Point3D.h"

class Entity {
public:
    enum EntityType
    {
        None,
        Player,
        NPC,
        Mob
    };

    Entity();

    Entity(const std::string& name, const Point2D& location);
    Entity(const std::string& name, const Point3D& location);

    Entity(const Entity& from);
    Entity& operator=(const Entity& from);
    ~Entity();



    void move_to(const Point2D* to);
    void move_to(const Entity& to);

    virtual bool is_alive() const;

    int get_id() const;
    Point2D* get_location() const;

    double get_distance_to_2d(const Entity& to) const;
    double get_distance_to(const Entity& to) const;

    std::string get_name() const;

    virtual EntityType get_type() const = 0;
private:
    static int counter;
    int id;
    std::string name;
    Point2D* location;
    EntityType type;
};


#endif //HOMEWORK3_2019_ENTITY_H
