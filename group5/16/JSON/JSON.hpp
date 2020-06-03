#ifndef JSON_HPP
#define JSON_HPP

#include <string>

enum class JSONType
{
    OBJECT,
    ARRAY
};

template <typename T>
class JSON
{
protected:
    JSONType type;
public:
    virtual T getValue(const std::string&) const = 0;
    virtual JSONType getType() const = 0;
    virtual ~JSON() = default;
};

#endif // !JSON_HPP