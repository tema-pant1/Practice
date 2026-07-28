#pragma once

#include <string>


class Account {
private:
    enum {ACCOUNT_SIZE = 10};
    std::string name;
    std::string account;
    double balance;

public:
    Account();
    Account(const std::string& nm, const std::string& acnt, double bl);
    void Show() const;
    void add(double sum);
    void withdraw(double sum);
};