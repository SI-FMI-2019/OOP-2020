#include <iostream>

/**
 * Write template function to square numbers
 */
template <class T>
T square(T a) {
    return a * a;
}

/**
 * Write template class to encapsulate a static template object
 */
template <class T>
class EncapsualatedStatic {
   private:
    T obj;

   public:
    T get() const {
        return obj;
    }

    void set(T newValue) {
        obj = newValue;
    }
};

/**
 * Write a template class to encapsulate a dynamic template object
 */
template <class T>
class EncapsulatedDynamic {
   private:
    T* ptr;

   public:
    T get() const {
        return *ptr;
    }
    void set(T newValue) {
        *ptr = newValue;
    }

    EncapsulatedDynamic() {
        ptr = new T;
    }

    EncapsulatedDynamic(const EncapsulatedDynamic& rhs) {
        ptr = new T(rhs.get());
    }

    EncapsulatedDynamic& operator=(const EncapsulatedDynamic& rhs) {
        if (this != &rhs) {
            delete ptr;
            ptr = new T(rhs.get());
        }

        return *this;
    }

    ~EncapsulatedDynamic();  // Declared outside
};

template <class T>
EncapsulatedDynamic<T>::~EncapsulatedDynamic() {
    delete ptr;
}

int main() {
    double d = 1.1;
    // std::cout << square(d) << "\n";

    EncapsualatedStatic<int> encapsulatedInt;
    encapsulatedInt.set(12);
    // std::cout << encapsulatedInt.get() << "\n";

    EncapsualatedStatic<float> encapsulatedFloat;
    encapsulatedFloat.set(54.42);
    // std::cout << encapsulatedFloat.get() << "\n";

    EncapsulatedDynamic<int> i;
    i.set(12);
    // std::cout << i.get() << "\n";

    EncapsulatedDynamic<char> c;
    c.set('@');
    // std::cout << c.get() << "\n";
}
