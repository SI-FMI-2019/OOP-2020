//
// Created by lyubo on 30.04.20 г..
//

#include "Entity.h"

Entity::Entity(): name("")
{
    Entity::counter += 1;
    this->id = Entity::counter;
    this->location = new Point2D();
    this->type = EntityType::None;
}

Entity::Entity(const Entity& from)
{
    Entity::counter += 1;
    this->id = Entity::counter;

    this->name = from.name;
    this->type = from.type;

    if(from.location->get_type() == Point2D::Dimension::_2D)
    {
        this->location = new Point2D(*from.location);
    }
    else
    {
        this->location = new Point3D(from.location->get_x(), from.location->get_y(), ((Point3D*)from.location)->get_z());
    }
}
Entity& Entity::operator=(const Entity& from)
{
    if(this != &from)
    {
        delete this->location;

        this->name = from.name;
        this->type = from.type;

        if(from.location->get_type() == Point2D::Dimension::_2D)
        {
            this->location = new Point2D(*from.location);
        }
        else
        {
            this->location = new Point3D(from.location->get_x(), from.location->get_y(), ((Point3D*)from.location)->get_z());
        }
    }
    return *this;
}
Entity::~Entity()
{
    delete this->location;
}

Entity::Entity(const std::string& name, const Point2D& location)
{
    Entity::counter += 1;
    this->id = Entity::counter;

    this->name = name;
    this->location = new Point2D(location);
}

Entity::Entity(const std::string& name, const Point3D& location)
{
    Entity::counter += 1;
    this->id = Entity::counter;

    this->name = name;
    this->location = new Point3D(location);
}

void Entity::move_to(const Point2D *to)
{
    if(this->location->get_type() == to->get_type())
    {
        // 3D/3D
        // 2D/2D

        delete this->location;

        if(to->get_type() == Point2D::Dimension::_2D)
        {
            //2D/2D
//           Point2D temp = *to;
//           this->location = new Point2D(temp); //CopyConstructor of Point2D()
            this->location = new Point2D(to->get_x(), to->get_y());
        }
        else
        {
            //3D/3D
            //Point3D temp = *((Point3D*)to);
            //this->location = new Point3D(temp);

            this->location = new Point3D(to->get_x(), to->get_y(), ((Point3D*)to)->get_z());
        }
    }
    else
    {
        //3D/2D
        //2D/3D

        delete this->location;

        if(to->get_type() == Point2D::Dimension::_2D)
        {
            //3D/2D
            //Point3D temp(to->get_x(), to->get_y());
            //this->location = new Point3D(temp);
            this->location = new Point3D(to->get_x(), to->get_y(), 0); //TODO - may be incorrect
        }
        else
        {
            //2D/3D
            //Point2D temp(to->get_x(), to->get_y());
            //this->location = new Point2D(temp);

            this->location = new Point2D(to->get_x(), to->get_y());
        }
    }
}

void Entity::move_to(const Entity &to) {
    this->move_to(to.location);
}


bool Entity::is_alive() const
{
    return true;
}

int Entity::get_id() const
{
    return this->id;
}
Point2D* Entity::get_location() const
{
    return this->location;
}

double Entity::get_distance_to_2d(const Entity& to) const
{
    Point2D this_point = *this->location;
    Point2D other_point = *to.location;
    return this_point.get_distance_to(&other_point);
}
double Entity::get_distance_to(const Entity& to) const
{
    if(this->location->get_type() == to.location->get_type() && this->location->get_type() == Point2D::Dimension::_3D)
    {
        return this->location->get_distance_to(to.location);
    }
    else
    {
        return this->get_distance_to_2d(to);
    }
}

std::string Entity::get_name() const
{
    return this->name;
}

