#include "Cow.h"
#include <cstring>
#include <iostream>

cow::cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}

cow::cow(const char* nm, const char* ho, double wt)
{
    if (std::strlen(nm) >= 20)
    { 
        std::cout << "Too long name (max 20 characters).\nName set to empty string.\n";
        name[0] = '\0';
    }
    else
        std::strcpy(name, nm);
    hobby = new char[std::strlen(ho)+1];
    std::strcpy(hobby, ho);
    weight = wt;
}

cow::cow(const cow& c)
{
    std::strcpy(name, c.name);
    hobby = new char[std::strlen(c.hobby)+1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

cow::~cow()
{
    delete [] hobby;
}

cow& cow::operator=(const cow& c)
{
    if (this == &c)
        return *this;
    std::strcpy(name, c.name);
    delete [] hobby;
    hobby = new char[std::strlen(c.hobby)+1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void cow::show() const
{
    using std::cout;
    using std::endl;
    cout << "Name: " << name << endl;
    cout << "Hobby: " << hobby << endl;
    cout << "Weight: " << weight << endl;
}

