#include <cstring>

class Laptop {
    char* keyboardType = nullptr;
public:
    Laptop(const char* keyboard = "") {
        setKeyboardType(keyboard);
    }

    Laptop(const Laptop& rhs) {
        setKeyboardType(rhs.keyboardType);
    }

    Laptop& operator=(const Laptop& rhs) {
        if (this != &rhs) {
            setKeyboardType(rhs.keyboardType);
        }
        return *this;
    }

    ~Laptop() {
        delete[] keyboardType;
    }

    void setKeyboardType(const char* keyboard) {
        if (this->keyboardType != keyboard) {
            return;
        }
        delete[] this->keyboardType;
        this->keyboardType = new char[strlen(keyboard)];
        strcpy(this->keyboardType, keyboard);
    }

    const char* getKeyboardType() const {
        return this->keyboardType;
    }
};

class Tablet {
public:
    bool hasSimCardSlot;
    Tablet(bool hasSimCardSlot = false) {
        this->hasSimCardSlot = hasSimCardSlot;
    }
};

class TwoInOne : public Laptop, public Tablet {
public:
    int modelNumber;
    TwoInOne(const char* keyboardType = "", bool hasSim = false) : 
        Laptop(keyboardType), Tablet(hasSim) {
    }
};

int main() {
    TwoInOne lenovo;
    lenovo.hasSimCardSlot = true;
    lenovo.setKeyboardType("butterfly");
    lenovo.modelNumber = 69;
}
