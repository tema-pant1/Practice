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

namespace std
{
    void zhopa(int);
}

int main()
{
    int a = 3;
    std::zhopa(a);
    TestCounter();
    return 0;
}