#include "tv.h"

#include <cstring>

TV::TV() {
    this->name = new char[0];
}

TV::TV(const char *name) {
    size_t nameLen = strlen(name);
    this->name = new char[nameLen + 1];
    strcpy(this->name, name);
}

TV::~TV() {
    delete[] this->name;
}

TV::TV(const TV &rhs) {
    size_t nameLen = strlen(rhs.name);
    this->name = new char[nameLen + 1];
    strcpy(this->name, rhs.name);
}

TV &TV::operator=(const TV &rhs) {
    if (this != &rhs) {
        delete[] this->name;

        size_t nameLen = strlen(rhs.name);
        this->name = new char[nameLen + 1];
        strcpy(this->name, rhs.name);
    }
    return *this;
}

const char *TV::getName() const {
    return this->name;
}
