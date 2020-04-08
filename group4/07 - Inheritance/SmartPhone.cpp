#include "SmartDevice.h"
#include "SmartPhone.h"

void SmartPhone::setName(const char* newName) {
    SmartDevice::setName(newName);
}

const char* SmartPhone::getName() {
    return SmartDevice::getName();
}
