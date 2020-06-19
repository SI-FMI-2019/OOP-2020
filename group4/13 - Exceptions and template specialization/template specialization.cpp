#include <iostream>

template <class T>
T add(T a, T b) {
    return a + b;
}

template <class T>
T boolSafeAdd(T a, T b) {
    return a + b;
}

template <>
bool boolSafeAdd(bool a, bool b) {
    return (a + b) % 2;
}

int main() {
    int five = add<int>(2, 3);
    std::cout << five << "\n"; // Outputs 5 correctly
    int overflowPls = add<bool>(true, true);
    std::cout << overflowPls << "\n";  // Outputs 1 when we want to overflow like int and get 0

    int six = boolSafeAdd<int>(2, 4);
    std::cout << six << "\n"; // Outputs 6 correctly
    int thisWillOverflow = boolSafeAdd<bool>(true, true);
    std::cout << thisWillOverflow << "\n";  // Outputs 0, because (1 + 1) mod 2 = 0
}
