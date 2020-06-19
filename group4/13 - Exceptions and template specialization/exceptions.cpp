#include <exception>
#include <iostream>
#include <string>

int divide(int number, int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Zero vidision is not allowed");
    }
    return number / divisor;
}

class LimitedVector {
    int MAX_SIZE = 10;
    int* data = new int[MAX_SIZE];

   public:
    LimitedVector() {
        for (int i = 0; i < MAX_SIZE; i++) {
            data[i] = i;
        }
    }

    int operator[](int index) {
        if (0 <= index && index < MAX_SIZE) {
            return data[index];
        } else if (index >= MAX_SIZE) {
            throw std::overflow_error(std::to_string(index) + " doesn't exist in the array");
        } else {
            throw std::underflow_error(std::to_string(index) + " doesn't exist in the array");
        }
    }
};

int main() {
    int five = divide(10, 2);
    std::cout << five << "\n";  // Outputs 5 correctly
    // int infinity = divide(10, 0); // Throws exception

    unsigned int infinity;
    try {
        infinity = divide(10, 0);  // This throws an exception but it will be caught
    } catch (std::invalid_argument ex) {
        std::cout << ex.what() << "\n";
        infinity = -1;  // That's infinity in C++ limited memory world
    }

    std::cout << "Infinity = " << infinity << "\n";

    LimitedVector myVector;
    std::cout << "Vector[3] = " << myVector[3] << "\n";
    try {
        std::cout << "Vector[25] = " << myVector[25] << "\n";
    } catch (std::overflow_error ex) {
        std::cout << "Error: " << ex.what() << "\n";
    }

    try {
        std::cout << "Vector[-1] = " << myVector[-1] << "\n";
    } catch (std::overflow_error ex) {
        std::cout << "Error: " << ex.what() << "\n";
    } catch (std::exception ex) {
        std::cout << "Error: unknown error occurred\n";
    }
}
