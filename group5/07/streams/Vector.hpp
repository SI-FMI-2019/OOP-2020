#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(const size_t);
    Vector(const Vector&);
    Vector<T>& operator=(const Vector&);
    ~Vector();

    void pushBack(const T);
    T popBack();
    void printVector() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const Vector<U>&);

    template<typename U>
    friend std::istream& operator>>(std::istream&, Vector<U>&);

private:
    T* values;
    size_t size;
    size_t capacity;

    void copyFrom(const Vector&);
    void deallocateValues();
    void resize();
};

template <typename T>
Vector<T>::Vector()
    : values(nullptr)
    , size(0)
    , capacity(0)
{
}

template <typename T>
Vector<T>::Vector(const size_t capacity)
    : values(new T [capacity])
    , size(0)
    , capacity(capacity)
{
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    copyFrom(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this != &other)
    {
        deallocateValues();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    deallocateValues();
}

template <typename T>
void Vector<T>::pushBack(const T value)
{
    if (this->values == nullptr)
    {
        this->capacity = 1;
        this->values = new T [this->capacity];
    }
    else
    {
        resize();
    }

    this->values[this->size] = value;
    this->size++;
}

template <typename T>
T Vector<T>::popBack()
{
    if (this->size > 0)
    {
        T last = this->values[this->size - 1];
        this->size--;
        T value;
        this->values[this->size] = value;
        return last;
    }
    T result;
    return result;
}

template <typename T>
void Vector<T>::printVector() const
{
    for (size_t i = 0; i < this->size; i++)
    {
       std::cout << this->values[i] << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::copyFrom(const Vector& other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->values = new T [other.capacity];
    for (size_t i = 0; i < other.size; i++)
    {
        this->values[i] = other.values[i];
    }
}

template <typename T>
void Vector<T>::deallocateValues()
{
    if (this->values != nullptr)
    {
        delete[] this->values;
    }
}

template <typename T>
void Vector<T>::resize()
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        T* placeholder = new T [this->capacity];
        for (size_t i = 0; i < this->size; i++)
        {
            placeholder[i] = this->values[i];
        }
        deallocateValues();
        this->values = placeholder;

        // std::cout << "resized" << std::endl;
    }
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& v)
{
    for (size_t i = 0; i < v.size; i++)
    {
        os << v.values[i] << " ";
    }
    os << "\n";
    
    return os;
}

template<typename U>
std::istream& operator>>(std::istream& is, Vector<U>& v)
{
    int number = 0;
    std::cout << "Enter number of elements: ";
    is >> number;

    for (size_t i = 0; i < number; i++)
    {
        U temp;
        is >> temp;
        v.pushBack(temp);
    }

    return is;    
}

#endif // VECTOR_HPP