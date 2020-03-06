#include "Dispencer.hpp"
#include <iostream>
using namespace std;

int main(){
    Dispencer d;
    d.setQuantity(0);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.setCapacity(10);
    cout << "Capacity:" << d.getCapacity() << "\n";

    d.fillBottle(4);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.fillDispencer(8);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.fillBottle(5);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.fillDispencer(8);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.fillBottle(6);
    cout << "Quantity:" << d.getQuantity() << "\n";
    d.fillBottle(6);
    cout << "Quantity:" << d.getQuantity() << "\n";
    
    
    return 0;
}
