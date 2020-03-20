#ifndef CUP_HPP
#define CUP_HPP

#include "Picture.hpp"

enum Color
{
    RED,
    BLUE,
    GREEN,
    WHITE
};

class Cup
{
public:
    Cup();
    Cup(double, double, Color);
    Cup(const Cup&);
    ~Cup();
    void fill(const double);
    double getQuantity() const;
private:
    unsigned id;
    static unsigned nextId;
    double quantity;
    double capacity;
    Color color;
    Picture picture;
};

#endif // CUPP_HPP