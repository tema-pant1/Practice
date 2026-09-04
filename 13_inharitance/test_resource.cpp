#include "resource.h"
#include <iostream>

int main()
{
    taggedResource a("123", 2, 67);
    a.show();
    taggedResource b = a;
    b.setId("six seven");
    a.show();
    b.show();

    namedResource a1("popa", 2, "pant1");
    namedResource b1 = a1;
    namedResource c1;
    c1 = b1;
    std::cout << "----------------\n";
    a1.show();
    b1.show();
    c1.show();
    return 0;
}