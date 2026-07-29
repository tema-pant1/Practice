#include "Move.h"
#include <iostream>

void Move::showmove() const
{
    std::cout << "x - " << x << std::endl;
    std::cout << "y - " << y << std::endl;
}

Move Move::add(const Move& m) const
{
    Move result;
    result.x = x+m.x;
    result.y = y+m.y;
    return result;
}