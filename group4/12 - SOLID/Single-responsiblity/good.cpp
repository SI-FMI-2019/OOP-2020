#include <iostream>
#include <vector>

using namespace std;

class VectorConsoleWriter {
   public:
    template <class T>
    void print(vector<T> vect) const {
        for (size_t i = 0; i < vect.size(); i++) {
            cout << vect.at(i) << ", ";
        }
    }
};

int main() {
    vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    VectorConsoleWriter writer;
    writer.print(ints);
}
