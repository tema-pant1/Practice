#include "List.h"
#include <iostream>

void show(Item& itm)
{
    std::cout << itm << std::endl;
}

void sqrt(Item& itm)
{
    itm *= itm;
}

using namespace LIST;

int main()
{
    List a;
    Item i = 0;
    while(!a.is_full())
        a.push_back(i++);
    a.visit(show);
    std::cout << "\n------------\n";
    a.visit(sqrt);
    a.visit(show);
    return 0;
}