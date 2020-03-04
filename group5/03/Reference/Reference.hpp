#ifndef REFERENCE_HPP
#define REFERENCE_HPP

class Reference
{
public:
    Reference();
    Reference(const int);
    Reference(const Reference&);
    ~Reference();
private:
    int* resource;
};

#endif