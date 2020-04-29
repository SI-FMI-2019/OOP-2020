#include <iostream>

struct Base {
	int a;
};

struct ChildA : public Base {
    ChildA() {
        a = 1;
    }
};

struct ChildB : public Base {
    ChildB() {
        a = 2;
    }
};

struct GrandChild : public ChildA, public ChildB {
    // contains int a; twice
};

int main() {
    GrandChild obj;
    // std::cout << obj.a << "\n"; // Error because a is ambiguous
    // std::cout << obj.Base::a << "\n"; // Base is ambiguous, because it exists twice
    
    // Access ambiguous fields using casting
    std::cout << ((ChildA)obj).a << "\n";  // Prints 1
    std::cout << ((ChildB)obj).a << "\n";  // Prints 2

    // Access ambiguous fields with their absolute name
    std::cout << obj.ChildA::a << "\n";
    std::cout << obj.ChildB::a << "\n";

}
