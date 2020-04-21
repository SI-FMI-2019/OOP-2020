#include "Block.hpp"

Block::Block(const char* address,
            const unsigned floors, 
            const char* date,
            const double price,
            const bool hasSharedSpace)
    : Building(address, floors, date, price)
    , hasSharedSpace(hasSharedSpace)
{
}

bool Block::getHasSharedSpace() const
{
    return this->hasSharedSpace;
}

std::ostream& operator<<(std::ostream& os, const Block& block)
{
    os << "Block\n";
    os << block.address << "\n";
    os << block.floors << "\n";
    os << block.date << "\n";
    os << block.price << "\n";
    os << block.hasSharedSpace << "\n";

    return os;
}