#include "Dispencer.hpp"

void Dispencer::setCapacity(unsigned int capacity){
    this->capacity = capacity;
} 

void Dispencer::setQuantity(unsigned int quantity){
    if(quantity >= capacity){
        this->quantity = capacity;
    }
    else{
        this->quantity = quantity;
    }
}

unsigned int Dispencer::getCapacity() const{
    return capacity;
}

unsigned int Dispencer::getQuantity() const{
    return this->quantity;
}

void Dispencer::fillDispencer(unsigned int quantity){
    cout << "Fill dispencer:" << quantity << "\n";
    unsigned int afterFill = this->quantity + quantity;
    if(afterFill >= capacity){
        this->quantity = capacity;
    }
    else if(quantity > 0){
        this->quantity = afterFill;
    }
}

bool Dispencer::fillBottle(unsigned int containerCapacity){
    cout << "Fille bottle:" << containerCapacity << "\n";
    if(containerCapacity >= quantity){
        cout << "Not enough water in dispencer!\n";
        return 1;
    } 
    quantity -= containerCapacity;
    return 0;
}