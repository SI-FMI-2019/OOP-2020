#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Building.hpp"

class Block : public Building
{
public:
    Block(const char*, 
          const unsigned, 
          const char*,
          const double,
          const bool);

    Block() = default;
    Block(const Block&) = default;
    Block& operator=(const Block&) = default;
    ~Block() = default;    

    bool getHasSharedSpace() const;
private:
    bool hasSharedSpace;

    friend std::ostream& operator<<(std::ostream& os, const Block&);
};

#endif // !BLOCK_HPP