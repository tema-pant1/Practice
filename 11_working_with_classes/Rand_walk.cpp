#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>

#include "Vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0, 359.0);
    double direction;
    Vector step;
    unsigned long steps(0), attempts(0);
    unsigned long max_step, min_step;
    double average_steps;
    Vector result;
    double target; 
    double dstep;
    unsigned long n;
    string fname = "Rand_walk.txt";
    ofstream file(fname);
    if (!file.is_open())
    {
        cout << "Error with open file with path " << fname << endl;
        cout << "Program is terminating with code 1.\n";
        return 1; 
    }
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        max_step = 0;
        min_step = numeric_limits<unsigned long>::max();
        average_steps = 0;
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter attempts: ";
        if (!(cin >> attempts))
            break;
        n = attempts;
        file << "Target Distance: " << target << ", Step Size: " << dstep;
        file << ", Attempts: " << attempts << endl;
        while(n--)
        {
            while (result.magval() < target)
            {
                direction = dist(gen);
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            if (steps < min_step) 
                min_step = steps;
            if (steps > max_step)
                max_step = steps;
            average_steps += steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        file << "Max steps: " << max_step << endl;
        file << "Min steps: " << min_step << endl;
        file << "Average steps: " << average_steps / attempts << endl;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}