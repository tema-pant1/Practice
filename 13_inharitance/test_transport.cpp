#include "transport.h"

using namespace std;

int main()
{
    vehicle kalina(35, 70);
    kalina.show();
    SportsCar bugati(100, 300);
    bugati.show();
    bugati.boost();
    bugati.show();
    return 0;
}