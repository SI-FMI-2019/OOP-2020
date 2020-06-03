#ifndef JSONARRAY_HPP
#define JSONARRAY_HPP

#include "JSON.hpp"
#include "JSONObject.hpp"
#include <iostream>
#include <vector>

template <typename T>
class JSONArray : public JSON<T>
{
public:
    JSONArray();
    virtual T getValue(const std::string&) const override;
    virtual JSONType getType() const override;
    virtual ~JSONArray() = default;

    void insert(const std::string&, const T&);
    void insert(JSON<T>*);

    size_t getSize() const;
private:
    std::vector<JSON<T>*> jsons;
};

template <typename T>
JSONArray<T>::JSONArray()
{
    this->type = JSONType::ARRAY;
}

template <typename T>
JSONType JSONArray<T>::getType() const
{
    return this->type;
}

template <typename T>
void JSONArray<T>::insert(const std::string& key, const T& value)
{
    JSONObject<T>* temp = new JSONObject<T>;
    temp->setKey(key);
    temp->setValue(value);
    jsons.push_back(temp);
}

template <typename T>
void JSONArray<T>::insert(JSON<T>* newJSON)
{
    jsons.push_back(newJSON);
}

template <typename T>
size_t JSONArray<T>::getSize() const
{
    return jsons.size();
}

template <typename T>
T JSONArray<T>::getValue(const std::string& key) const
{
    for (auto iter = jsons.begin(); iter != jsons.end(); iter++)
    {
        if ((*iter)->getType() == JSONType::OBJECT)
        {
            JSONObject<T>* temp = static_cast<JSONObject<T>*>((*iter));
            if (temp->getKey() == key)
                return temp->getValue("undefined");
        } 
        else if ((*iter)->getType() == JSONType::ARRAY)
        {
            return (*iter)->getValue(key);
        }
    }
    std::cout << "invalid key" << std::endl;
    return T();
}

#endif // JSONARRAY_HPP