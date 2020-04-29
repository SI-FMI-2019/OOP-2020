#include <iostream>

struct Base {
	int a;
};

struct ChildA : virtual public Base {
    ChildA() {
        a = 1;
    }
};

struct ChildB : virtual public Base {
    ChildB() {
        a = 2;
    }
};

struct D : public ChildA, public ChildB {
    // contains int a; twice
};

int main() {
	D obj;
    std::cout << obj.a << "\n"; // Prints 2
    // 2 because ChildB is the second inherited class, so its constructor,
    // which sets a = 2, is called after that of ChildA
}
