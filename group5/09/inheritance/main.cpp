#include <iostream>

class Material
{
public:
    Material() = default;

    Material(const double density)
        :density(density)
    {
    }

    double getDensity() const
    {
        return this->density;
    }
private:
    double density;
};

class BuildingMaterial : virtual public Material
{
public:
    BuildingMaterial() = default;
    BuildingMaterial(const int strength)
        : strength(strength)
    {    
    }

    int getStrength() const
    {
        return this->strength;
    }
private:
    int strength;
};

enum class Taste
{
    SALT,
    SWEET,
    SOUR
};

class FoodMaterial : virtual public Material
{
public:
    FoodMaterial() = default;
    FoodMaterial(const Taste& taste, const double density)
        : Material(density)
        , taste(taste)
    {
    }

    Taste getTaste() const
    {
        return this->taste;
    }
private:
    Taste taste;
};

class Chocolate : public FoodMaterial, public BuildingMaterial
{
public:
    Chocolate() = default;
    Chocolate(const double weigth)
        : weigth(weigth)
    {
    }

    double getWeigth() const
    {
        return this->weigth;
    }
private:
    double weigth;
};

int main()
{
    Chocolate ch;
    std::cout << ch.getDensity() << std::endl;
    return 0;
}