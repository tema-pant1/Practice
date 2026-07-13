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

vector<int> golf_entering()
{
    vector<int> results;
    int game(0);
    cout << "Enter results of your golf games (max 10).\n";
    cout << "To stop entering enter -1\n";
    cin >> game;
    while (results.size() < 10 && !cin.fail() && game >= 0)
    {
        results.push_back(game);
        if (results.size() < 10) cin >> game;
    }
    return results;
}

double golf_average(const vector<int> results)
{
    double average;
    for (int elem: results) average+=elem;
    average /= results.size();
    return average;
}

void golf_output(vector<int> results, double average)
{
    cout << "Your results:\n";
    for (int i = 0; (i+1) < results.size(); i++)
        cout << results[i] << ", ";
    cout << results[results.size()-1] << endl;
    cout << "Average result: " << average << endl;
}

void golf()
{
    vector<int> results = golf_entering();
    double average = golf_average(results);
    golf_output(results, average);

}

int main()
{
    golf();
    return 0;
}