#include <iostream>
#include "classic.h"

using namespace std;

void bravo(const cd& disk);

int main()
{
    cd c1("Beatles", "Capilot", 14, 35.5);
    classic c2 = classic("Piano Sonata in B flat, Fantasia in C", 
                         "Alfred Brendel", "Philips", 2, 57.17);

    cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.report();
    c2.report();
    cout << endl;

    cout << "Using type cd * pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();
    cout << endl;

    cout << "Calling a fuction with a Cd reference argument:\n";
    bravo(c1);
    bravo(c2);
    cout << endl;
    
    cout << "testing assigment:\n";
    classic copy;
    copy = c2;
    copy.report();
    return 0;
}

void bravo(const cd& disk)
{
    disk.report();
}