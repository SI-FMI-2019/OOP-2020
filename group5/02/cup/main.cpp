#include "cup.hpp"
#include <iostream>

int main()
{
    Cup* myCup;
    myCup = new Cup;

    myCup->setCapacity(250);
    myCup->setQuantity(123);

    myCup.setCapacity(250);
    myCup.setQuantity(125);

    myCup.fill(12);
    std::cout << myCup.getQuantity() << std::endl;
    
    return 0;
}