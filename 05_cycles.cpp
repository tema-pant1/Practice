#include <iostream>
#include <array>
#include <string>

const int ArSize = 101;

using namespace std;

void sum_between()
{
    int begin, end, sum = 0;
    cout << "Enter begin of sum: ";
    cin >> begin;
    cout << "Enter end of sum: ";
    cin >> end;
    for (int i = begin+1; i < end; i++) sum+=i;
    cout << "Sum of numbers between " << begin << " and " << end << " is - " << sum << endl;
}

void formore()
{
    array<long double, ArSize> factorials;
    factorials[0] = factorials[1] = 1.0L;

    for (int i = 2; i < ArSize; i++) factorials[i] = i*factorials[i-1];

    for (int i = 0; i < ArSize; i++) cout << i << "! = " << factorials[i] << endl;
}

void count_numbers()
{
    int number, sum = 0;
    cout << "Enter number\n";
    cin >> number;
    while (number)
    {
        sum += number;
        cout << "Current sum: " << sum << endl;
        cout << "Enter number\n";
        cin >> number;
    }
}

void bankir()
{
    float Cleo_balance(100.0), Dafna_balance(100.0);
    string delay = "          ";
    int years = 0;
    cout << "years" << delay << "Cleo" << delay << "Dafna" << endl;
    while (Dafna_balance >= Cleo_balance)
    {
        cout << years;
        if (years++ < 10) cout << " ";
        cout << delay << Cleo_balance << delay << Dafna_balance << endl;
        Dafna_balance += 10.0;
        Cleo_balance += 0.05*Cleo_balance;
    }
    cout << years << delay <<Cleo_balance << delay << Dafna_balance << endl;
}

void book_seller()
{
    array<string, 12> mounth = 
    {"January", "February", "March", "April", 
    "May", "June", "July", "August",
    "September", "October", "November", "December"};
    array<array<int, 12>, 3> earnings;
    int sum(0), local_sum(0), current;
    cout << "Enter how many books you sold in every month\n";
    for (auto year: earnings)
    {
        local_sum = 0;
        for (int i = 0; i < 12; i++)
        {
            cout << mounth[i] << ": ";
            cin >> current;
            year[i] = current;
            local_sum += current;
        }
        cout << "In this year you sold " << local_sum << " books\n";
        sum += local_sum;
    }
    cout << "Total earning for 3 year - " << sum << " books\n";
}

struct car
{
    string manufacturer;
    int year;
};

void car_collection()
{
    int size;
    cout << "Enter how many cars you wnat to store in coolection? ";
    cin >> size;
    car* collection = new car [size];
    for (int i = 0; i < size; i++)
    {
        cout << "Car #" << (i+1) << "\nEnter manufacturer: ";
        cin.get(); //Разобраться почему здесь нужен get
        getline(cin, collection[i].manufacturer);
        cout << "Enter year of manufacture: ";
        cin >> collection[i].year;
    }

    cout << "Your collection:\n";
    for (int i = 0; i < size; i++) 
    cout << collection[i].year << " " << collection[i].manufacturer << endl;

}

int main()
{
    car_collection();
    return 0;
}