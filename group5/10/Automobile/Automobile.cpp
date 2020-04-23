#include "Automobile.hpp"
#include <cstring>

void Automobile::copyData(const unsigned hp, 
					   const char* model, 
					   const unsigned year,
					   const double price)
{
	this->hp = hp;
	this->year = year;
	this->price = price;

	this->model = new char [strlen(model) + 1];
	strncpy(this->model, model, strlen(model));
	this->model[strlen(this->model)] = '\0';
}

Automobile::Automobile()
	: Automobile(0, "undefined", 0, 0.0)
{
}

Automobile::Automobile(const unsigned hp, 
					   const char* model, 
					   const unsigned year,
					   const double price)
{
	copyData(hp, model, year, price);
}

Automobile::Automobile(const Automobile& other)
	: Automobile(other.hp, other.model, other.year, other.price)
{
}

Automobile& Automobile::operator=(const Automobile& other)
{
	if (this != &other)
	{
		delete[] this->model;
		copyData(other.hp, other.model, other.year, other.price);
	}
	return *this;
}

Automobile::~Automobile()
{
	delete[] this->model;
}

void Automobile::upgrade(const unsigned newHp)
{
	this->hp += newHp;
}

unsigned Automobile::getHp() const
{
	return this->hp;
}