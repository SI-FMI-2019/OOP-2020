#include <iostream>
#include "person.h"

person::person() {
    this->name = new char[1];
    this->name[0] = '\0';
}
person::person(const person &from) {
    copy_char_array(from.name);
}

person& person::operator=(const person &from) {
    if(this != &from)
    {
        delete[] this->name;

        copy_char_array(from.name);
    }
    return *this;
}

person::~person() {
    delete[] this->name;
}

void person::copy_char_array(const char * from) {
    int length = strlen(from);
    this->name = new char[length + 1];
    strcpy(this->name, from);
    this->name[length] = '\0';
}

void person::set_name(const char *new_name) {
    delete[] this->name;
    copy_char_array(new_name);
}

void person::set_age(const int &new_age)
{
    this->age = new_age;
}

void person::print() const
{
    std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
}

char* person::get_name() const{
    return this->name;
}

int person::get_age() const
{
    return this->age;
}

std::ostream& operator<<(std::ostream& out, const person& to_print)
{
    out << "Name: " << to_print.name << ", Age: " << to_print.age << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, person& to_write)
{
    std::cout << "Please enter your name: ";
    char buffer[1000];
    in >> buffer;
    to_write.set_name(buffer);

    std::cout << "Please enter your age: ";
    int buffer_age;
    in >> buffer_age;
    to_write.set_age(buffer_age);

    return in;
}