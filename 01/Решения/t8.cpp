#include <iostream>
#include <cmath>

struct QuadraticEquation {
    double a;
    double b;
    double c;

    double discriminant() const {
        return b * b - 4 * a * c;
    }

    bool isDiscriminantNegative() const {
        return discriminant() < 0;
    }

    double solution1() const {
        if (isDiscriminantNegative()) {
            std::cout << "There are no real solutions\n";
            return 0;
        }

        double numerator = -b + sqrt(discriminant());
        double denominator = 2 * a;

        return numerator / denominator;
    }

    double solution2() const {
        if (isDiscriminantNegative()) {
            std::cout << "There are no real solutions\n";
            return 0;
        }

        double numerator = -b - sqrt(discriminant());
        double denominator = 2 * a;

        return numerator / denominator;
    }
};

void runTests() {
    QuadraticEquation t1;
    t1.a = 1;
    t1.b = -4;
    t1.c = 4;
    // Solutions are 2 and 2 for x^2 -4x + 4 = = (x-2)(x-2) = 0
    std::cout << "Discriminant: " << t1.discriminant() << "\n";
    std::cout << "Solutions: " << t1.solution1();
    std::cout << " and " << t1.solution2() << "\n";
}

int main() {
    runTests();
}
