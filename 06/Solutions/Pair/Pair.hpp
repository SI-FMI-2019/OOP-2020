#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T>
class Pair
{
public:
    Pair() = default;
    Pair(const T&, const T&);
    Pair(const Pair<T>&) = default;
    Pair<T>& operator=(const Pair<T>&) = default;
    ~Pair() = default;

    void setFirst(const T&);
    T getFirst() const;

    void setSecond(const T&);
    T getSecond() const;

    T getMax() const;

    bool operator==(const Pair<T>&) const;
    bool operator!=(const Pair<T>&) const;
private:
    T first;
    T second;
};

template <typename T>
Pair<T>::Pair(const T& first, const T& second)
    : first(first)
    , second(second)
{
}

template <typename T>
void Pair<T>::setFirst(const T& first)
{
    this->first = first;
}

template <typename T>
T Pair<T>::getFirst() const
{
    return this->first;
}

template <typename T>
void Pair<T>::setSecond(const T& second)
{
    this->second = second;
}

template <typename T>
T Pair<T>::getSecond() const
{
    return this->second;
}

template <typename T>
T Pair<T>::getMax() const
{
    return (this->first > this->second) ? this->first : this->second;
}

template <typename T>
bool Pair<T>::operator==(const Pair<T>& other) const
{            
    return (this->first == other.first && 
            this->second == other.second) ? true : false;
}

template <typename T>
bool Pair<T>::operator!=(const Pair<T>& other) const
{
    return !(*this == other);
}

#endif // PAIR_HPP