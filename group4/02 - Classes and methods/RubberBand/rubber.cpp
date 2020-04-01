#include <iostream>

// Write a program to calculate a rubber band's
// max length, which is calculated by multiplying
// the original length and a stretch coefficient

struct RubberBand {
 private:
    int length = 1;
    int coefficient = 1;
 public:
    int maxLength = 0;

    void setLen(int len) {
        this->length = len;
        calcMaxLen();
    }
    void setCoef(int coef) {
        this->coefficient = coef;
        calcMaxLen();
    }
    void calcMaxLen() {
        maxLength = length * coefficient;
    }
};

int main() {
    RubberBand band;
    band.setLen(3);
    band.calcMaxLen();
    std::cout << band.maxLength << "\n";  // 3
    band.setCoef(5);
    std::cout << band.maxLength << "\n";  // 15;
}
