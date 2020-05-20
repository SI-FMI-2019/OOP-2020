#include <vector>
#include <iostream>

using namespace std;

template <class T>
class AdvancedVector : public vector<T> {
   public:
    void print() const {
        for(size_t i = 0; i < this->size(); i++) {
            cout << this->at(i) << ", ";
        }
    }
    // ^ Bad idea to couple the vector with the console
    // They are not connected in any way
    // Just like a car is not connected with your bank account
};

int main() {
    AdvancedVector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    ints.print();
}
