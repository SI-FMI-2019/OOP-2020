#pragma once

#include <cstring>
#include <iostream>
class Engine {
   private:
    char* name = nullptr;

   public:
    int power;

    const char* getName() const;
    void setName(const char* newName);
    Engine(int newPower = 100, const char* newName = "");
    Engine(const Engine& rhs);
    ~Engine();

    Engine& operator=(const Engine& rhs);
};
