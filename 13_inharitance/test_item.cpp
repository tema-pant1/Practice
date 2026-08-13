#include "item.h"
#include <iostream>

using namespace std;

int main() 
{
    item i1("Artem", 120);
    i1.show();
    discounted_item di1("Nikita", 100, 20);
    di1.show();
    cout << "Total price: " << di1.final_price() << endl;
    item& si = di1;
    item* pi = &di1;
    return 0;
}