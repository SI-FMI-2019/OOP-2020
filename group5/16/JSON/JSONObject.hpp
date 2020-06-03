#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP

#include "JSON.hpp"

template <typename T>
class JSONObject : public JSON<T>
{
public:
    JSONObject();
    virtual T getValue(const std::string&) const override;
    virtual JSONType getType() const override;
    virtual ~JSONObject() = default;

    void setKey(const std::string&);
    void setValue(const T&);

    std::string getKey() const;
private:
    std::string key;
    T value;
};

template <typename T>
JSONObject<T>::JSONObject()
{
    this->type = JSONType::OBJECT;
}

template <typename T>
JSONType JSONObject<T>::getType() const
{
    return this->type;
}

template <typename T>
T JSONObject<T>::getValue(const std::string& key) const
{
    return this->value;
}

template <typename T>
void JSONObject<T>::setKey(const std::string& newKey)
{
    this->key = newKey;
}

template <typename T>
void JSONObject<T>::setValue(const T& newValue)
{
    this->value = newValue;
}

template <typename T>
std::string JSONObject<T>::getKey() const
{
    return this->key;
}

#endif