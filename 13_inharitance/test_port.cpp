#include "port.h"

using namespace std;

void test_port();

void test_vintage();

int main()
{
    // test_port();
    // cout << endl;
    test_vintage();
    return 0;
}

void test_port()
{
    port a("Jack Danialse", "ruby", 3), b;
    port c = a;
    b = a;

    cout << "testing constructors:\n";
    a.show();
    b.show();
    c.show();
    cout << endl;

    cout << "testing operators:\n";
    a += 2;
    cout << a << endl;
    a -= 4;
    cout << a << endl;
    a -= 4;
    cout << a << endl;
    cout << endl;
}

void test_vintage()
{
    vintagePort a("Martini", 25, "The Noble", 2025), b;
    vintagePort c = a;
    cout << "test default constructor:\n";
    b.show();
    cout << endl;
    b = a;

    cout << "test others constructor and operator =:\n";
    cout << a << endl;
    cout << b << endl;
    c.show();
    cout << endl;
    
    cout << "Test operator +:\n";
    a += 5;
    a.show();
    cout << endl;

}