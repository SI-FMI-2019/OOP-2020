#include <iostream>
#include <random>
class Safe{
public:
    Safe()
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        std::uniform_int_distribution<> distr(25, 63); // define the range
        this->number = distr(eng) << ' '; // generate numbers
    }
private:
    int number;

    friend void hacker(const Safe& to_hack);
    friend class Hacker;
};

void hacker(const Safe& to_hack)
{
    std::cout << to_hack.number;
}

class Hacker{
public:
    void get_the_number(const Safe& to_hack)
    {
        std::cout << to_hack.number;
    }
};

int main()
{
    Safe a;
    Hacker b;
    //hacker(a);

    b.get_the_number(a);
    return 0;
}