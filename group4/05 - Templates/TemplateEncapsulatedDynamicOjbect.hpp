# pragma once
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

// Declare a methoud outside requires to write template <class T> again
template <class T>
EncapsulatedDynamic<T>::~EncapsulatedDynamic() {
    delete ptr;
}
