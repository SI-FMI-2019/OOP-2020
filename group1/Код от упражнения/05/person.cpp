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

char* person::get_name() const{
    return this->name;
}