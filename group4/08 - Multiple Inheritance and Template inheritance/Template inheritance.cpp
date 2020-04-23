#include <iostream>

template <class VALUE>
class Variable {
public:
    VALUE value;
};

template <class KEY, class VALUE>
class Pair : public Variable<VALUE> {
public:
    KEY key;
};

int main() {
    Pair<char, int> charTranslater;
    
    charTranslater.key = 'a';
    charTranslater.value = 'a';

    std::cout << charTranslater.key << " is with ASCII code " << charTranslater.value;
}
