#pragma once

#include <string>

class item {
private:
    std::string name;
    double price;

public:
    item(std::string nm = "no name", double pr = 0.0);

    double get_price() const {return price;}
    void show() const;
};

class discounted_item : public item {
private:
    double discount;

public:
    discounted_item(std::string nm = "no name", double pr = 0.0, double disc = 0.0);
    discounted_item(double disc, const item& itm);

    double final_price() const;
    void reset_discount(double d) {discount = d;}  
};