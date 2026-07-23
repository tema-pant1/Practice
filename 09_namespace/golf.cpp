#include "golf.h"
#include <iostream>
#include <cstring>

void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    using std::cin;
    using std::cout;
    char name[Len];
    int hc;
    cout << "Enter name: ";
    cin.get(name, Len);
    while(cin.get() != '\n');
    cout << "Enter handicap: ";
    cin >> hc;
    cin.get();
    setgolf(g, name, hc);
    if (name[0] == '\0') return 0;
    else return 1;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    using std::cout;
    using std::endl;
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}
