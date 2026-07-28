#include "Golf.h"
#include <iostream>
#include <cstring>

golf::golf(const char* name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int golf::SetGolf()
{
    using std::cin;
    using std::cout;
    char name[LEN];
    int hc;
    cout << "Enter name: ";
    cin.get(name, LEN);
    while(cin.get() != '\n');
    cout << "Enter handicap: ";
    cin >> hc;
    cin.get();
    *this = golf(name, hc);
    if (name[0] == '\0') return 0;
    else return 1;
}

void golf::SetHandicap(int hc)
{
    handicap = hc;
}

void golf::Show() const
{
    using std::cout;
    using std::endl;
    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}