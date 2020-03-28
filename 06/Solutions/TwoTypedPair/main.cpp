#include "Pair.hpp"

#include <iostream>

int main()
{
    Pair<int, double> firstPair(4, 3.18);
    Pair<int, double> secondPair(4, 3.18);

    std::cout << (firstPair == secondPair) << std::endl;

    Pair<char, int> ascii('A', 'A');
    std::cout << ascii.getFirst() << " symbol's ASCII code is ";
    std::cout << ascii.getSecond() << std::endl;

     return 0;
}