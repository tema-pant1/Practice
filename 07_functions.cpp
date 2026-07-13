#include <iostream>
#include <vector>
#include <array>

using namespace std;

double harmonic_mean(const double x, const double y)
{
    return (2.0*x*y)/(x+y);
}

void calculate_harmonic()
{
    vector<array<double, 3>> results;
    double a, b, harmonic;
    array<double, 3> current;
    cout << "Enter couple of numbers. (to stop one of the number must be a 0):\n";
    cin >> a; cin >> b;
    while (a*b != 0)
    {
        current[2] = harmonic_mean(a, b);
        current[0] = a; current[1] = b;
        results.push_back(current);
        cin >> a; cin >> b;
    }
    cout << "harmonic mean of numbers:\n";
    for (auto elem: results)
        cout << elem[0] << ", " << elem[1] << " - " << elem[2] << endl;
}   

int main()
{
    calculate_harmonic();
    return 0;
}