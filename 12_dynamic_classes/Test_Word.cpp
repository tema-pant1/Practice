#include "Word.h"

void func1(word& obj)
{
    std::cout <<"string passed by reference: " <<  obj << std::endl;
}

void func2(word obj)
{
    std::cout << "string passed by value: " << obj << std::endl;
}

int main()
{
    using namespace std;
    {
        word wd1, wd2("Artem");
        cout << "wd1: " << wd1 << endl;
        cout << "wd2: " << wd2 << endl;
        func1(wd2);
        cout << "wd2: " << wd2 << endl;
        func2(wd2);
        cout << "wd2: " << wd2 << endl;
        word wd3("Poppa");
        word wd4;
        wd4 = wd3;
        cout << "wd3: " << wd3 << endl;
        cout << "wd4: " << wd4 << endl;
    }
}