#include <iostream>
#include "person.h"
#include <limits>

using std::cout;
using std::endl;
using std::cin;


void person::ignore(std::istream& is, const char delim) const
{
    is.ignore(std::numeric_limits<std::streamsize>::max(), delim);
}

void person::set()
{
    cout << "Enter person name: ";
    getline(cin, name);
    cout << "Enter person id: ";
    cin >> id;
    ignore();
}

void person::show() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
}

void teacher::set()
{
    person::set();
    cout << "Enter subject: ";
    getline(cin, subject);
    ignore();
}

void teacher::show() const
{
    cout << "Category: teacher\n";
    person::show();
    cout << "Subject: " << subject << endl;
}

void coach::set()
{
    person::set();
    cout << "Enter sport: ";
    getline(cin, sport);
    ignore();
}

void coach::show() const
{
    cout << "Category: coach\n";
    person::show();
    cout << "Sport: " << sport << endl;
}

