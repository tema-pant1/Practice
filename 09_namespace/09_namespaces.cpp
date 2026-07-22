#include <iostream>

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

int main()
{
    TestCounter();
    return 0;
}