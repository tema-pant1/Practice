#include "sales.h"
#include <cfloat>
#include <iostream>

namespace SALES
{
    void setSales(Sales& s, const double ar[], int n)
    {
        double average(0), max(ar[0]), min(ar[0]);
        for (int i = 0; (i < n) && (i < QUARTERS); i++)
        {    
            s.sales[i] = ar[i];
            average += ar[i];
            if (ar[i] > max) max = ar[i];
            if (ar[i] < min) min = ar[i];
        }
        average /= QUARTERS;
        for (int i = (QUARTERS-n); i > 0; i--)
        {    
            s.sales[QUARTERS-i] = 0;
        }
        if (0 > max) max = 0;
        if (0 < min) min = 0;
        s.average = average;
        s.min = min;
        s.max = max;
    }

    void setSales(Sales& s)
    {
        using namespace std;
        cout << "Enter sales from " << QUARTERS << " quarters:\n";
        double max(-DBL_MAX), min(DBL_MAX), average(0);
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "#" << (i+1) << endl;
            cin >> s.sales[i];
            average += s.sales[i];
            if (s.sales[i] > max) max = s.sales[i];
            if (s.sales[i] < min) min = s.sales[i];
        }
        average /= QUARTERS;
        s.average = average;
        s.min = min;
        s.max = max;
    }

    void showSales(const Sales& s)
    {
        using namespace std;
        cout << "Quarters:\n";
        for (int i = 0; i < QUARTERS; i++) 
            cout << s.sales[i] << endl;
        cout << "Average: " << s.average << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
    }
}