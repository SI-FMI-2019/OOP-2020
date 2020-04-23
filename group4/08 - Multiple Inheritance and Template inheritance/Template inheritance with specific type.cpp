#include <vector>
#include <cstring>
#include <iostream>


// Template inheritance used to inherit the template vector
// as a vector of specific type - char
class String : protected std::vector<char> {
public:
    String() {
        this->push_back('\0');
    }

    String(const char* str) {
        size_t strLen = strlen(str);
        for (size_t i = 0; i <= strLen; i++) {
            this->push_back(str[i]);
        }
    }

    const char* getStr() const {
        return &this->at(0);
    }
};

int main() {
    String s("Hello");
    std::cout << s.getStr();
}
