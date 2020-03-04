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
    Cup();                       // default constructor
    Cup(double, double, Color);  // parameter constructor
    Cup(const Cup&);             // copy constructor
    ~Cup();
    // void setQuantity(const double);                      // Do I really
    // void setCapacity(const double);                      // need them?
    void fill(const double);
    // void setColor(const Color&);                         // And that?
    double getQuantity() const;
private:
    double quantity;
    double capacity;
    Color color;
};

#endif // CUPP_HPP