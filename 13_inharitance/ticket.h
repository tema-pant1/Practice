#pragma once

#include <string>

class ticket {
private:
    std::string event;
    double price;

public:
    ticket(std::string evnt = "none", double pr = 0.0);

    virtual void ShowInfo() const;
    virtual double FinalPrice() const;
    virtual ~ticket();
};

class VIPticket : public ticket {
private:
    double surcharge;
    std::string perk;

public:
    VIPticket(std::string evnt = "none", double pr = 0.0,
              double srch = 0.0, std::string prk = "none");
    VIPticket(double srch, std::string perk, const ticket& t);

    virtual void ShowInfo() const;
    virtual double FinalPrice() const;
    virtual ~VIPticket();
};