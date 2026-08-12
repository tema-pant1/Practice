#include "Stock.h"
#include <cstring>
#include <ios>

stock::stock()
{
    company = new char[8];
    std::strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

stock::stock(const char* co, long n, double pr)
{
    int ln = std::strlen(co);
    company = new char[ln + 1];
    std::strcpy(company, co);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

stock::~stock()
{
    delete [] company;
}

void stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else 
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void stock::update(double price)
{
    share_val = price;
    set_tot();
}

const stock& stock::topval(const stock& s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

std::ostream& operator<<(std::ostream& os, const stock& s)
{
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize  prec = os.precision(3);
    os << "Company: " << s.company
       << " Shares: " << s.shares << "\n";
    os << " Share Price: $" << s.share_val;
    os.precision(2);
    os << " Total Worth: $" << s.total_val << "\n";
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
} 