#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class ConsoleWriter {
   public:
    template <class T>
    void print(T arr) const {
        for (auto it = arr.begin(); it != arr.end(); it++) {
            cout << *it << ", ";
        }
        cout << "\n";
    }
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

    // We can add another type that can be iterated without changing
    // the ConsoleWriter class
    set<int> ordered_ints;
    ordered_ints.insert(2);
    ordered_ints.insert(3);
    ordered_ints.insert(1);
    writer.print(ordered_ints);
}
