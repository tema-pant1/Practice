#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
    Fraction fr1, fr2(2), fr3(1, 3);
    fr1.show();
    fr2.show();
    fr3.show();    
    fr1 = fr2 + fr3;
    fr2 = fr3 - fr1;
    cout << "--------------\n";
    fr1.show();
    fr2.show();
    fr3.show();
    fr3 = fr3 * 2;
    cout << "--------------\n";
    fr3.show();
    Fraction fr4(1, 2), fr5(2, 2), fr6(3, 2);
    fr1 = fr4 + fr5 + fr6;
    cout << "--------------\n";
    cout << "fr1 = " << fr1 << "\n";
    return 0;
}