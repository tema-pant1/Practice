#include <iostream>
#include <string>
#include <new>

using namespace std;

void Counter()
{
    static int cnt;
    cnt++;
    cout << "Function was called " << cnt << " times\n";
}

void TestCounter()
{
    for (int i = 0; i < 5; i++) Counter();
}

void strcount(const string& str)
{
    static int total = 0;
    int cnt = 0;
    cout << str << " contains ";
    cnt = str.size();
    total += cnt;
    cout << cnt << " characters\n";
    cout << total << " charactes total\n";
}

void cnt_str()
{
    string input;
    cout << "Enter a line:\n";
    while(getline(cin, input))
    {
        if (input.empty()) break;
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
    }
    cout << "Bye!\n";

}

int main()
{
    partition_new();
    return 0;
}