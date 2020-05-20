#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ConsoleWriter {
   public:
    template <class T>
    void print(vector<T> vect) const {
        for (size_t i = 0; i < vect.size(); i++) {
            cout << vect.at(i) << ", ";
        }
        cout << "\n";
    }

    void print(string str) const {
        for (size_t i = 0; i < str.size(); i++) {
            cout << str.at(i) << ", ";
        }
        cout << "\n";
    }

    // Add more methods when you need more types
    // ^ Bad decision because it introduces more work
};

int main() {
    vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    ConsoleWriter writer;
    writer.print(ints);

    string hello = "Hello";
    writer.print(hello);
}
