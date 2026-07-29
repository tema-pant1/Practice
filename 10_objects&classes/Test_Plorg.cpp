#include "Plorg.h"

int main()
{
    Plorg pl1("Artem"), pl2("Nikita", 3), pl3;
    pl1.show();
    pl2.show();
    pl3.show();
    pl1.set_CI(67);
    pl1.show();
    return 0;
}