#include <iostream>
#include "Timestamp.hpp"

int main()
{
    Timestamp timestamp;
    timestamp.convertToTimestamp(3664*20);
    timestamp.print();

    Timestamp other;
    other.convertToTimestamp(20);
    other.print();

    timestamp.add(other);
    timestamp.print();

    std::cout << timestamp.convertToSeconds() << std::endl;
    
    return 0;
}