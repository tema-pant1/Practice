#include <cstring>
#include <iostream>
#include "classic.h"

classic::classic(const char* cmp, const char* perf, const char* lb, int s, double pltm) : 
                 cd(perf, lb, s, pltm)
{
    composition = new char[std::strlen(cmp) + 1];
    std::strcpy(composition, cmp);
}

classic::classic(const classic& c) : cd(c)
{
    composition = new char[std::strlen(c.composition) + 1];
    std::strcpy(composition, c.composition);
}

classic::classic() : cd()
{
    composition = new char[6];
    std::strcpy(composition, "none.");
}

classic& classic::operator=(const classic& c)
{
    if (this == &c)
        return *this;

    cd::operator=(c);
    delete[] composition;
    composition = new char[std::strlen(c.composition) + 1];    
    std::strcpy(composition, c.composition);
    return *this;
}

classic::~classic()
{
    delete[] composition;
}

void classic::report() const
{
    std::cout << "Composition: " << composition << std::endl;
    cd::report();
}