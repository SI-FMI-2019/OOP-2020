#pragma once
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
