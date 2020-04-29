#include <iostream>

class Base {
public:
    // Declaring a method virtual makes it virtual in all derived classes,
    // without the need to declare it virtual in them too
    virtual void print() const {
        std::cout << "inside Base\n";
    }

    // If the class is polymorphic (has at least one virtual function)
    // the destructor must be virtual as well
    virtual ~Base() { }
};

class Derived : public Base {
public:
    // "virtual" and "override" are optional and help code readability
    // Even if these keywords are omitted the method will be virtual because
    // it was virtual in the base class
    virtual void print() const override {
        std::cout << "inside Derived\n";
    }

    // The destructor is automatically virtual, because it was virtual
    // in the base class
};

int main() {
    /* Initializing objects works just fine */
    // Base base;
    // base.print();
    // Derived derived;
    // derived.print();


    /* Dynamically allocating objects */
    // Derived* basePtr = new Base; // Not allowed
    // Derived* derivedPtr = new Derived; // Works but this is nothing new


    /* Polymorphism in action */
    Base* basePtr = new Base;
    basePtr->print();  // prints "inside Base"
    Base* derivedPtr = new Derived;
    derivedPtr->print();  // prints "inside Derived"

    // Don't forget to free the memory :)
    delete basePtr;
    delete derivedPtr;
}
