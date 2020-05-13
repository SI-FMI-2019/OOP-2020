// https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct functor {
    void operator()(int& a) {
        a += 10;
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // Increase all values by 10
    functor func;
    for_each(v.begin(), v.end(), func);
    for(int i : v) {
        cout << i << ", ";
    }
    cout << "\n";

    // Decrease all values by 10
    int decreaseBy = 10;
    for_each(v.begin(), v.end(), [decreaseBy](int& a) { a -= decreaseBy; });
    for(int i : v) {
        cout << i << ", ";
    }
    cout << "\n";
    
    int ten = []() -> int { return 10; }();
    cout << ten << "\n";
}
