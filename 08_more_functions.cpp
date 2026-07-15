#include <iostream>
#include <string>

using namespace std;

int cnt_str = 0;

void print_str(const string* str, int cnt = 0)
{
    if (!cnt)
    {
        cout << *str << endl;
        cnt_str++;
        return;
    }
    else 
    {
        for (int i = 0; i < cnt_str; i++) cout << *str << endl;
        cnt_str += cnt_str;
    }
}

void unused_str()
{
    string p = "Pant1";
    string* ptr_p = &p;
    print_str(ptr_p);
    print_str(ptr_p, 67);
    print_str(ptr_p, 123);
}

int main()
{
    unused_str();
    return 0;
}