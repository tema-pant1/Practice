#include "Sales.h"

using namespace SALES;

const int sz = 2;

int main()
{
    Sales year1, year2;
    double arr[sz] = {23.4, 12.3};
    year1 = Sales(arr, sz);
    year2.SetSales();
    year1.Show();
    year2.Show();
    return 0;
}