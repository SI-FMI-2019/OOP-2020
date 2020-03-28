#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

template <typename T>
class Stack
{
public:
    Stack() = default;
    Stack(const Stack<T>&) = default;
    Stack<T>& operator=(const Stack<T>&) = default;
    ~Stack() = default;

    void push(const T);
    T pop();

    size_t getSize() const;
private:
    Vector<T> vector;
};

template <typename T>
void Stack<T>::push(const T value)
{
    vector.pushBack(value);
}

template <typename T>
T Stack<T>::pop()
{
    return this->vector.popBack();
}

template <typename T>
size_t Stack<T>::getSize() const
{
    return this->vector.getSize();
}

#endif // STACK_HPP