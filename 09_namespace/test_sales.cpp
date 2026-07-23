#include "sales.h"

using namespace SALES;
using namespace std;

int sz = 2;

int main()
{
    Sales year1, year2;
    double arr[sz] = {23.4, 12.3};
    setSales(year1, arr, sz);
    setSales(year2);
    showSales(year1);
    showSales(year2);
    return 0;
}