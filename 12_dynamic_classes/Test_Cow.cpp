#include "Cow.h"

int main()
{
    cow c1, c2("Pant", "tennis", 100);
    cow c3 = c2;
    c1 = c2;
    c1.show();
    c2.show();
    c3.show();
    return 0;
}
