#include "SmartDevice.h"
#include <cstring>
SmartDevice::SmartDevice(const char* name) {
    setName(name);
}

SmartDevice::~SmartDevice() {
    delete[] name;
}

SmartDevice::SmartDevice(const SmartDevice& rhs) {
    setName(rhs.name);
}

SmartDevice& SmartDevice::operator=(const SmartDevice& rhs) {
    if (this != &rhs) {
        setName(rhs.name);
    }
    return *this;
}

const char* SmartDevice::getName() const {
    return name;
}

void SmartDevice::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
