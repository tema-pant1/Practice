#include "wine.h"
#include <ctime>
#include <iostream>
#include <limits>
int wine::getYear() 
{
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    return local_time->tm_year + 1900;
}

const int wine::YEAR = wine::getYear();

wine::wine() : label("none."), size(DEFAULT_SIZE)
{
    bottles.second = arrayInt(DEFAULT_SIZE);
    bottles.first = arrayInt(DEFAULT_SIZE);
}

wine::wine(const char* l, int y, const int yr[], const int bot[]) : label(l), size(y)
{
    bottles.first = arrayInt(yr, size);
    bottles.second = arrayInt(bot, size);
}

wine::wine(const char* l, int y) : label(l), size(y)
{
    bottles.first = arrayInt(size);
    bottles.second = arrayInt(size);
}

void wine::inputReset(std::istream& is)
{
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void wine::getBottles()
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter " << label << " data for " << size << " year(s):\n";
    for (int i = 0; i < size; i++)
    {
        cout << "#" << (i + 1) << endl;
        cout << "Enter year: ";
        while (!(cin >> bottles.first[i]))
        {
            inputReset();
            cout << ">>";
        }
        cout << "Enter bottles for that year: ";
        while (!(cin >> bottles.second[i]))
        {
            inputReset();
            cout << ">>";
        }
    }
}

void wine::show() const
{
    using std::cout;
    using std::endl;
    int year_w = 7;
    int cnt_w = 3;
    cout << "Wine: " << label << endl;
    cout.width(year_w);
    cout << "Year";
    cout << "    Bottles\n";
    for (int i = 0; i < size; i++)
    {
    cout.width(year_w);
    cout << bottles.first[i] << "    ";
    cout << bottles.second[i] << endl;       
    }
}