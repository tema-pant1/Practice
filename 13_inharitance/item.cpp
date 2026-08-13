#include "item.h"
#include <ios>
#include <iostream>

item::item(std::string nm, double pr) : name(nm), price(pr) {}

void item::show() const
{
    using std::ios_base;
    ios_base::fmtflags orig = std::cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = std::cout.precision(2);
    std::cout << name << ": $" << price << std::endl;
    std::cout.setf(orig, ios_base::floatfield);
    std::cout.precision(prec);
}

discounted_item::discounted_item(std::string nm, double pr, double disc) : item(nm, pr)
{
    if (disc > 100 || disc < 0)
    {
        std::cout << "Incorrect discount! Discount set to 0.\n";
        discount = 0;
    }
    else
        discount = disc;
}

discounted_item::discounted_item(double disc, const item& itm) : item(itm) 
{
    if (disc > 100 || disc < 0)
    {
        std::cout << "Incorrect discount! Discount set to 0.\n";
        discount = 0;
    }
    else
        discount = disc;
}

double discounted_item::final_price() const
{
    return get_price() * (100.0 - discount) / 100.0;
}

