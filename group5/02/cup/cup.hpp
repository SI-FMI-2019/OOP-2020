#ifndef CUP_HPP
#define CUP_HPP

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
    void setQuantity(const double);
    void setCapacity(const double);
    void fill(const double);
    void setColor(const Color&);
    double getQuantity() const;  
private:
    double quantity;
    double capacity;
    Color color;
};

#endif // CUPP_HPP