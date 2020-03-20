#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

class Vector
{
public:
    Vector();
    Vector(const size_t);
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    ~Vector();

    // 1 2 3 4 5 6 -> pushBack(7) => 1 2 3 4 5 6 7
    void pushBack(const int);
    void printVector() const;
private:
    int* values;
    size_t size;
    size_t capacity;

    void copyFrom(const Vector&);
    void deallocateValues();
    void resize();
};

#endif // VECTOR_HPP