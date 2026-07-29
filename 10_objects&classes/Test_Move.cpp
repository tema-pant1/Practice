#include "Move.h"

int main()
{
    Move mv1(2, 3), mv2(3), mv3;
    mv1.showmove();
    mv2.showmove();
    mv3.showmove();
    mv3.reset(67, 52);
    mv1 = mv1.add(mv2);
    mv1.showmove();
    mv2.showmove();
    mv3.showmove();
}