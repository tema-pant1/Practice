#include <limits>
#include "Stonewt.h"

const int LEN = 6;

int main()
{
    using namespace std;
    stonewt st1, st2(14.0), st3(1, 1.0);
    cout << st1 << endl;
    cout << st2 << endl;
    cout << st3 << endl;
    st3.set_lbs();
    st1 = st3 + st2;
    cout << "st3 + st2 = ";
    cout << st1 << endl;
    st1 = st3 - st2;
    cout << "st3 - st2 = " << st1 << endl;
    st1 = st3 * st2;
    st1.set_stone();
    cout << "st3 * st2 = " << st1 << endl;

    stonewt arr[6] = {stonewt(15.0), stonewt(3.0), stonewt(27.0)};
    stonewt st11(11, 0.0);
    stonewt min_st(numeric_limits<double>::max()), max_st;
    int cnt = 0;
    cout << "Enter weight in pounds: \n";
    for (int i = 3; i < LEN; i++)
    {
        cout << i+1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < LEN; i++)
    {
        if (arr[i] < min_st) 
            min_st = arr[i];
        if (arr[i] > max_st) 
            max_st = arr[i];
        if (arr[i] >= st11)
            cnt++;
    }
    cout << "Minimum: " << min_st << endl;
    cout << "Maximum: " << max_st << endl;
    cout << "Objects than >= 11: " << cnt << endl; 
}