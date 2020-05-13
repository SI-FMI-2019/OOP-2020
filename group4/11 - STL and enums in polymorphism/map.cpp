#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string, string> pairs;
    pairs["myKey"] = "myValue";
    if (pairs.count("myKey") == 1) {
        cout << "myKey exists and its value is " << pairs["myKey"] << "\n";
    } else {
        cout << "myKey does not exist\n";
    }
}
