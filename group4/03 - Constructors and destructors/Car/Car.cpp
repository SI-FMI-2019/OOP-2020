#include "Car.h"

#include "Engine.h"

// Function to add another engine to the array with already existing engines

void Car::addEngine(const Engine& engine) {
    int newEngineCount = engineCount + 1;
    // Create a new array with bigger capacity to store the old engines + the new one
    Engine* newEngines = new Engine[newEngineCount];
    // Copy the old engines into the new array
    for (int i = 0; i < engineCount; i++) {
        newEngines[i] = engines[i];
    }
    // Add the new engine at the end
    newEngines[newEngineCount - 1] = engine;

    // Delete the old engines, as we don't need them anymore
    delete[] engines;
    // Make the engines variable point to the new location where the engines are stored
    engines = newEngines;
    engineCount++;  // Increase the engine count with 1 (because of the newly added engine)
}

// Default constructor
Car::Car() : engineCount(0) {
    engines = new Engine[0];
}

// Destructor
Car::~Car() {
    delete[] engines;
}

// Helper function to copy engines from one array to another
void Car::copyEngines(int copyCount, Engine* copyEngines) {
    engineCount = copyCount;
    engines = new Engine[engineCount];

    for (int i = 0; i < engineCount; i++) {
        engines[i] = copyEngines[i];
    }
}

// Copy constructor
Car::Car(const Car& rhs) {
    copyEngines(rhs.engineCount, rhs.engines);

    /* Does the same thing without using a function */

    // engineCount = rhs.engineCount;
    // engines = new Engine[engineCount];

    // for (int i = 0; i < engineCount; i++) {
    //     engines[i] = rhs.engines[i];
    // }
}

// Operator=
Car& Car::operator=(const Car& rhs) {
    if (this != &rhs) {
        delete[] engines;

        copyEngines(rhs.engineCount, rhs.engines);
    }
    return *this;
}
