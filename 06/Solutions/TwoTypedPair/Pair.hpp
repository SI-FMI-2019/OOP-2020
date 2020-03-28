#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T, typename U>
class Pair
{
public:
    Pair() = default;
    Pair(const T&, const U&);
    Pair(const Pair<T, U>&) = default;
    Pair<T, U>& operator=(const Pair<T, U>&) = default;
    ~Pair() = default;

    void setFirst(const T&);
    T getFirst() const;

    void setSecond(const U&);
    U getSecond() const;

    // T getMax() const; -> cannot get the max of two different types

    bool operator==(const Pair<T, U>&) const;
    bool operator!=(const Pair<T, U>&) const;
private:
    T first;
    U second;
};

template <typename T, typename U>
Pair<T, U>::Pair(const T& first, const U& second)
    : first(first)
    , second(second)
{
}

template <typename T, typename U>
void Pair<T, U>::setFirst(const T& first)
{
    this->first = first;
}

template <typename T, typename U>
T Pair<T, U>::getFirst() const
{
    return this->first;
}

template <typename T, typename U>
void Pair<T, U>::setSecond(const U& second)
{
    this->second = second;
}

template <typename T, typename U>
U Pair<T, U>::getSecond() const
{
    return this->second;
}

template <typename T, typename U>
bool Pair<T, U>::operator==(const Pair<T, U>& other) const
{            
    return (this->first == other.first && 
            this->second == other.second) ? true : false;
}

template <typename T, typename U>
bool Pair<T, U>::operator!=(const Pair<T, U>& other) const
{
    return !(*this == other);
}

#endif // PAIR_HPP