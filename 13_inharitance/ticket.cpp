#include "ticket.h"
#include <iostream>

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format SetFormat(std::ostream& os = std::cout);
void Restore(format frmt, precis prec, std::ostream& os = std::cout);

ticket::ticket(std::string evnt, double pr)
{
    event = evnt;
    price = pr;
}

void ticket::ShowInfo() const
{
    format frmt = SetFormat();
    precis prec = std::cout.precision(2);
    std::cout << "Event: " << event << " $" << price << std::endl;
    Restore(frmt, prec);
}

double ticket::FinalPrice() const
{
    return price;
}

ticket::~ticket()
{
    std::cout << "ticket destroyed.\n";
}

VIPticket::~VIPticket()
{
    std::cout << "VIPticket destroyed.\n";
}

VIPticket::VIPticket(std::string evnt, double pr, double srch, std::string prk) 
                    : ticket(evnt, pr), surcharge(srch), perk(prk) {}
                    
VIPticket::VIPticket(double srch, std::string prk, const ticket& t)
                    : ticket(t), surcharge(srch), perk(prk) {}

void VIPticket::ShowInfo() const
{
    format frmt = SetFormat();
    precis prec = std::cout.precision(2);
    ticket::ShowInfo();
    std::cout << "Perk: " << perk << " $" << surcharge << std::endl;
    std::cout << "Final price: $" << FinalPrice() << std::endl;
    Restore(frmt, prec);
}

double VIPticket::FinalPrice() const
{
    return ticket::FinalPrice() + surcharge;
}

format SetFormat(std::ostream& os)
{
    return os.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void Restore(format frmt, precis prec, std::ostream& os)
{
    os.setf(frmt, std::ios_base::floatfield);
    os.precision(prec);
}