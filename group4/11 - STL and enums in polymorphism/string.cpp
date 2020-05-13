#include <string>
#include <iostream>

using namespace std;

int main() {
    /* Basic usage */
    string s = "Hello";
    cout << s << "\n";
    s.append(" there,"); // Append changes the object
    cout << s << "\n";
    cout << s + " General Kenobi\n";  // Concatenation doesn't change the object
    cout << s;
    
    /* Iterating a string. The following do the exact same thing */
    for (size_t i = 0; i < s.length(); i++) {
        cout << s[i];
    }
    cout << "\n";

    for (size_t i = 0; i < s.length(); i++) {
        cout << s.at(i);
    }
    cout << "\n";

    for (string::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it;
    }
    cout << "\n";

    for (char c : s) {
        cout << c;
    }
    cout << "\n";

    /* Search */
    size_t position = s.find("there");
    if (position != s.npos) {
        cout << "Found 'there' at position " << position << "\n";
    } else {
        cout << "Could not find 'there'\n";
    }

    /* Erase */
    s.erase(s.begin(), s.begin() + 3);
    cout << s << "\n";

    /* Replace */
    string searchFor = "lo";
    size_t startPos = s.find(searchFor);
    if (startPos != s.npos) {
        s.replace(startPos, startPos + searchFor.length(), "Hey");
    }
    cout << s << "\n";
}
