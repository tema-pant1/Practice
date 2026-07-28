#include "Bank.h"

using namespace std;

int main()
{
    Account artem;
    artem = Account("Pantikhovskiy Artem", "1234567890",  150);
    artem.Show();
    artem.add(67.34);
    artem.Show();
    artem.withdraw(67.34);
    artem.Show();
    return 0;
}