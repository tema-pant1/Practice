#include "Person.h"

#include <iostream>
#include <ostream>

Person::Person(const std::string& ln, const char* fn)
{
    lname = ln;
    int i;
    for (i = 0; fn[i] != '\0' && i < LIMIT-1; i++)
    {
        fname[i] = fn[i];
    }
    fname[i] = '\0';    
}

void Person::Show() const
{
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << lname << ", " << fname << std::endl;
}