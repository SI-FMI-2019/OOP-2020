#include "Automobile.hpp"
#include "PetrolAutomobile.hpp"
#include "ElectricAutomobile.hpp"
#include "HybridAutomobile.hpp"
#include <iostream>

int main()
{
    Automobile myAutomobile(100, "My model", 2000, 4000);
    myAutomobile.upgrade(40);
    std::cout << myAutomobile.getHp() << std::endl;

    PetrolAutomobile myPetrolAutomobile(100, "My Petrol model", 2000, 4000, 4, 10.5, 35);
    myPetrolAutomobile.fuel(5);
    myPetrolAutomobile.upgrade(20);
    std::cout << myPetrolAutomobile.getHp() << std::endl;
    std::cout << myPetrolAutomobile.getTankQuantity() << std::endl;

    ElectricAutomobile myElectricAutomobile(100, "My Petrol model", 2000, 4000, 20000, 85);
    myElectricAutomobile.upgrade(30);
    myElectricAutomobile.charge(100);
    std::cout << myElectricAutomobile.getHp() << std::endl;
    std::cout << myElectricAutomobile.getPercentage() << std::endl;

    HybridAutomobile myHybridAutomobile(100, "My Petrol model", 2000, 4000, 4, 10.5, 35, 20000, 35, true);
    myHybridAutomobile.fuel(10);
    myHybridAutomobile.charge(0);
    myHybridAutomobile.switchEngines();
    std::cout << myHybridAutomobile.getTankQuantity() << std::endl;
    std::cout << myHybridAutomobile.getPercentage() << std::endl;
    std::cout << myHybridAutomobile.getIsEngineElectric() << std::endl;

    return 0;
}