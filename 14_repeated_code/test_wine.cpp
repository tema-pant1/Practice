#include "wine.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    wine holding(lab, yrs);

    holding.getBottles();
    holding.show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};

    wine more("Gushing Grape Red", YRS, y, b);
    more.show();
    cout << "Total bottles for " << more.getLabel() << ": " << more.sum() << endl;
    cout << "Bye.\n";
    return 0;
}

