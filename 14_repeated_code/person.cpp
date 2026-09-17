#include <iostream>
#include "person.h"
#include <limits>

using std::cout;
using std::endl;
using std::cin;


person::~person() {}

void person::data() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
}

void person::get()
{
    cout << "Enter person name: ";
    getline(cin, name);
    cout << "Enter person id: ";
    cin >> id;
    ignore();
}

void person::ignore(std::istream& is, const char delim) const
{
    is.ignore(std::numeric_limits<std::streamsize>::max(), delim);
}

void person::set()
{
    get();
}

void person::show() const
{
    data();
}

void teacher::data() const
{
    cout << "Teaching subject: " << subject << endl;
}

void teacher::get()
{
    cout << "Enter subject: ";
    getline(cin, subject);
}

void teacher::set()
{
    person::get();
    get();
}

void teacher::show() const
{
    person::data();
    data();
}

void coach::data() const
{
    cout << "Coaching sport: " << sport << endl;
}

void coach::get()
{
    cout << "Enter sport: ";
    getline(cin, sport);
}

void coach::set()
{
    person::get();
    get();
}

void coach::show() const
{
    person::data();
    data();
}

void teacherCoach::data() const
{
    teacher::data();
    coach::data();
}

void teacherCoach::get()
{
    teacher::get();
    coach::get();
}

void teacherCoach::show() const
{
    person::data();
    data();
}

void teacherCoach::set()
{
    person::get();
    get();
}
