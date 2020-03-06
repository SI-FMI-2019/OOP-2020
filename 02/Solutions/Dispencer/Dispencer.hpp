#include <iostream>
using namespace std;

class Dispencer{
private:
    unsigned int capacity;
    unsigned int quantity;
public:
    void setCapacity(unsigned int capacity);
    void setQuantity(unsigned int quantity);
    unsigned int getCapacity() const;
    unsigned int getQuantity() const;
    void fillDispencer(unsigned int quantity);
    bool fillBottle(unsigned int containerCapacity);
};