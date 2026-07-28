#include "Bank.h"
#include <cstring>
#include <iostream>

Account::Account()
{
    name = "";
    account = "";
    balance = 0;
}

Account::Account(const std::string& nm, const std::string& acnt, double bl)
{
    name = nm;
    if (acnt.size() != ACCOUNT_SIZE)
    {
        std::cout << "Warning! Incorrect length of account number.\nMust be " << ACCOUNT_SIZE;
        std::cout << " numbers. This info will be fill 0000000000\n";
        account = std::string(ACCOUNT_SIZE, '0');
    } 
    else account = acnt;
    balance = bl;
}

void Account::Show() const
{
    using std::endl;
    using std::cout;
    cout << "Name: " << name << endl;
    cout << "Account number: " << account << endl;
    cout << "Balance: " << balance << endl;
}

void Account::add(double sum)
{
    balance += sum;
}

void Account::withdraw(double sum)
{
    balance -= sum;
}