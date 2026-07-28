#include "Sales.h"
#include <cfloat>
#include <iostream>

namespace SALES
{
    Sales::Sales(const double ar[], int n)
    {
        max = ar[0];
        min = ar[0];
        average = 0;
        for (int i = 0; (i < n) && (i < QUARTERS); i++)
        {    
            sales[i] = ar[i];
            average += ar[i];
            if (ar[i] > max) max = ar[i];
            if (ar[i] < min) min = ar[i];
        }
        average /= ((n > QUARTERS) ? QUARTERS : n);
        for (int i = (QUARTERS-n); i > 0; i--)
            sales[QUARTERS-i] = 0;
    }

    Sales::Sales()
    {
        for (int i = 0; i < QUARTERS; i++)
            sales[i] = 0;
        max = 0;
        min = 0;
        average = 0;
    }

    void Sales::SetSales()
    {
        using namespace std;
        cout << "Enter sales from " << QUARTERS << " quarters:\n";
        max = -DBL_MAX;
        min = DBL_MAX;
        average = 0;
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "#" << (i+1) << endl;
            cin >> sales[i];
            average += sales[i];
            if (sales[i] > max) max = sales[i];
            if (sales[i] < min) min = sales[i];
        }
        average /= QUARTERS;
    }

    void Sales::Show() const
    {
        using namespace std;
        cout << "Quarters:\n";
        for (int i = 0; i < QUARTERS; i++) 
            cout << sales[i] << endl;
        cout << "Average: " << average << endl;
        cout << "Max: " << max << endl;
        cout << "Min: " << min << endl;
    }
}

