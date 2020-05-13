#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    for (int i : v) {
        std::cout << i;
    }
}
