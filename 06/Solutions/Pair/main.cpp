#include "Pair.hpp"

#include <iostream>

int main()
{
    Pair<int> myPair(8, 12);
    Pair<int> other(8, 12);

    std::cout << (myPair != other) << std::endl;
    std::cout << myPair.getMax() << std::endl;

    return 0;
}