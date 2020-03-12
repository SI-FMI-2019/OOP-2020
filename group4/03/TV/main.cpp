#include <iostream>

#include "tv.h"

int main() {
    TV sony("Sony");
    TV sonyCopy(sony);

    std::cout << sony.getName() << "\n";

    return 0;
}
