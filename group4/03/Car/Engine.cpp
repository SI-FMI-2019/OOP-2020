#include "Engine.h"

#include <cstring>
#include <iostream>

const char* Engine::getName() const {
    return name;
}

void Engine::setName(const char* newName) {
    int nameLen = strlen(newName);  // if newName = "asd" -> len = 3
    delete[] name;                  // delete nullptr = all gucci
    name = new char[nameLen + 1];   // allocate memory
    strcpy(name, newName);          // copy data into object
}

// Engine::Engine() : power(100) {
//     name = new char[1];
//     name[0] = '\0';  // == strcpy(name, "");
// }

Engine::Engine(int newPower, const char* newName) : power(newPower) {
    setName(newName);
}

Engine::Engine(const Engine& rhs) : power(rhs.power) {
    setName(rhs.name);
}

Engine::~Engine() {
    delete[] name;
}

Engine& Engine::operator=(const Engine& rhs) {
    if (this != &rhs) {
        power = rhs.power;
        setName(rhs.name);
    }
    return *this;
}
