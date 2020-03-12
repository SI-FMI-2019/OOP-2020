#include <iostream>

#include "Timestamp.h"

void debugPrint(Timestamp t) {
    std::cout << "Year = " << t.getYear();
    std::cout << " Month = " << t.getMonth();
    std::cout << " Day = " << t.getDay();
    std::cout << "\n";
}

int main() {
    // Default constructor
    // Values are (1, 1, 1)
    Timestamp d0;
    Timestamp d1 = Timestamp();
    debugPrint(d0);

    // Construcotr with parameters
    // Values are (1900, 2, 3)
    Timestamp p0(1900, 2, 3);
    Timestamp p1 = Timestamp(1900, 2, 3);
}
