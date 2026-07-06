#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string s("Hello");
    cout << "this is my string - " << s;
    cout << "\nit is lenght s - " << s.length();
    cout << "\ns is empty? - " << s.empty();
    s.clear();
    cout << "\ns is clear -" << s;
    s.push_back('k');
    cout << "\nnow s is - " << s;
    s.pop_back();
    s += "world";
    cout << "\nit is second character of s - " << s[2] << " and this is s -" << s;
    string b = s;
    cout << "\nI created b. b equal s - " << b;
    
}