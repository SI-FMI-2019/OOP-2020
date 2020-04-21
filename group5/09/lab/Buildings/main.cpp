#include "Building.hpp"
#include "Block.hpp"
#include "House.hpp"

#include <iostream>

int main()
{
    Building b("Sofia, Tsarigradsko Shose", 10, "10.03.2020", 56676324);

    Block myBlock("Sofia, Tsentar", 8, "10.04.1970", 143343, false);

    House myHouse("Pancharevo", 3, "04.06.2010", 45456456, 8, true);

    std::cout << b << std::endl;
    std::cout << myHouse << std::endl;
    std::cout << myBlock << std::endl;

    myBlock.setPrice(654);

    return 0;
}